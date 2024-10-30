#include "cameraview.h"
#include "ui_cameraview.h"

#include "CameraView.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QWindow>
#include <QWidget>
#include <QApplication>
#include <QScreen>
#include <QMenu>
#include <QMouseEvent>
#include <QFileDialog>
// #include <QMediaPlayer>
// #include <QVideoWidget>
#include <QDir>
#include <QUrl>
#include <QDateTime>
#include <cstring> // 添加此头文件以使用 strcpy
#include <QProcess>
CameraView::CameraView(QWidget *parent)
    : QWidget(parent), lUserID(-1), lRealPlayHandle(-1), isRecording(false) {

    recordSavePath = QCoreApplication::applicationDirPath();
    QDir dir(recordSavePath);
    dir.mkdir("savedVideo");
    recordSavePath = recordSavePath+"/savedVideo";
    qDebug()<<recordSavePath;
    // 设置窗口默认大小为 320x240
    resize(320, 240);

    // 初始化SDK
    NET_DVR_Init();

    // 设置设备信息
    NET_DVR_USER_LOGIN_INFO loginInfo = {0};
    strcpy(loginInfo.sDeviceAddress, "10.16.26.167"); // 设备IP
    loginInfo.wPort = 8000; // 设备端口
    strcpy(loginInfo.sUserName, "admin"); // 用户名
    strcpy(loginInfo.sPassword, "abcd1234"); // 密码

    NET_DVR_DEVICEINFO_V40 deviceInfo = {0};
    lUserID = NET_DVR_Login_V40(&loginInfo, &deviceInfo);
    if (lUserID < 0) {
        qDebug() << "Login error, error code:" << NET_DVR_GetLastError();
        return;
    }

    // 设置预览参数
    NET_DVR_PREVIEWINFO previewInfo = {0};
    previewInfo.hPlayWnd = reinterpret_cast<HWND>(this->winId()); // 传递窗口句柄
    previewInfo.lChannel = 1; // 通道号
    previewInfo.dwStreamType = 0; // 主码流
    previewInfo.dwLinkMode = 0; // TCP模式
    previewInfo.bBlocked = 1; // 阻塞方式

    // 启动预览
    lRealPlayHandle = NET_DVR_RealPlay_V40(lUserID, &previewInfo, nullptr, nullptr);
    if (lRealPlayHandle < 0) {
        qDebug() << "RealPlay error, error code:" << NET_DVR_GetLastError();
        return;
    }
}

CameraView::~CameraView() {
    // 停止预览
    if (lRealPlayHandle >= 0) {
        NET_DVR_StopRealPlay(lRealPlayHandle);
    }

    // 注销设备
    if (lUserID >= 0) {
        NET_DVR_Logout(lUserID);
    }

    // 释放SDK资源
    NET_DVR_Cleanup();
}

void CameraView::do_slots(slotName sName)
{
    switch (sName) {
    case slotName::startRecordingSlot:
        startRecordingSlot();
        break;
    case slotName::stopRecordingSlot:
        stopRecordingSlot();
        break;
    case slotName::viewHistorySlot:
        // viewHistorySlot();
        break;
    default:
        break;
    }
}

void CameraView::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        showContextMenu(event->pos());
    }
    QWidget::mousePressEvent(event);
}

void CameraView::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit switchToMain(this);
}

void CameraView::showContextMenu(const QPoint &pos) {
    QMenu contextMenu(tr("Context menu"), this);

    QAction actionSwitchToMain(tr("切换到主监控画面"), this);
    connect(&actionSwitchToMain, &QAction::triggered, this, [this]() { emit switchToMain(this); });
    contextMenu.addAction(&actionSwitchToMain);

    QAction actionStartRecording(tr("开始录屏"), this);
    connect(&actionStartRecording, &QAction::triggered, this, &CameraView::startRecordingSlot);
    contextMenu.addAction(&actionStartRecording);

    QAction actionStopRecording(tr("结束录屏"), this);
    connect(&actionStopRecording, &QAction::triggered, this, &CameraView::stopRecordingSlot);
    contextMenu.addAction(&actionStopRecording);

    // QAction actionViewHistory(tr("查看历史录屏文件"), this);
    // connect(&actionViewHistory, &QAction::triggered, this, &CameraView::viewHistorySlot);
    // contextMenu.addAction(&actionViewHistory);

    contextMenu.exec(mapToGlobal(pos));
}

void CameraView::startRecordingSlot() {
    if (!isRecording && lRealPlayHandle >= 0) {
        videoFileName = recordSavePath + "/video_" + QDateTime::currentDateTime().toString("yyyy_MM_dd_HH_mm_ss") + ".mp4";
        if (!videoFileName.isEmpty()) {
            // 将 recordingPath 转换为非 const char* 类型
            QByteArray recordingPathArray = videoFileName.toLocal8Bit();
            recordingPathArray.append("\0");
            char *recordingPathCStr = recordingPathArray.data();

            if (NET_DVR_SaveRealData(lRealPlayHandle, recordingPathCStr)) {
                isRecording = true;
                qDebug() << "Recording started, saving to:" << videoFileName;
            } else {
                qDebug() << "Failed to start recording, error code:" << NET_DVR_GetLastError();
            }
        }
    }
}

void CameraView::stopRecordingSlot() {
    if (isRecording && lRealPlayHandle >= 0) {
        if (NET_DVR_StopSaveRealData(lRealPlayHandle)) {
            isRecording = false;
            QString outputFileName = videoFileName.left(videoFileName.length() - 3) + "wmv";
            convertVideo(videoFileName,outputFileName);
            videoFileName = "";
            qDebug() << "Recording stopped.";
        } else {
            qDebug() << "Failed to stop recording, error code:" << NET_DVR_GetLastError();
        }
    }
}

// void CameraView::viewHistorySlot() {
//     QString fileName = QFileDialog::getOpenFileName(this, tr("打开录像文件"), "", tr("录像文件 (*.mp4)"));
//     if (fileName.isEmpty()) return;

//     QDialog *playbackDialog = new QDialog(this);
//     playbackDialog->setWindowTitle(tr("历史录像"));

//     QVBoxLayout *dialogLayout = new QVBoxLayout(playbackDialog);
//     QVideoWidget *videoWidget = new QVideoWidget(playbackDialog);
//     dialogLayout->addWidget(videoWidget);

//     QMediaPlayer *player = new QMediaPlayer(playbackDialog);
//     player->setVideoOutput(videoWidget);
//     player->setSource(QUrl::fromLocalFile(fileName));

//     playbackDialog->resize(640, 480);
//     playbackDialog->show();
//     player->play();
// }

void CameraView::convertVideo(const QString &inputFile, const QString &outputFile) {
    QProcess process;

    QString program = "ffmpeg";
    QStringList arguments;
    arguments << "-i" << QDir::toNativeSeparators(inputFile)
              << "-c:v" << "mpeg4"    // 使用MPEG-4视频编码器
              << "-c:a" << "wmav2"    // 使用AAC音频编码器
              << QDir::toNativeSeparators(outputFile);
    qDebug() << "Running ffmpeg with arguments:" << arguments.join(' ');

    process.start(program, arguments);

    if (!process.waitForStarted()) {
        qDebug() << "Failed to start ffmpeg process:" << process.errorString();
        return;
    }

    process.waitForFinished(-1);

    if (process.exitStatus() == QProcess::NormalExit && process.exitCode() == 0) {
        qDebug() << "Video conversion successful!";
    } else {
        qDebug() << "Video conversion failed:" << process.errorString();
    }

    // 删除原mp4文件
    QFile file(videoFileName);
    if (file.exists()) {
        if (file.remove()) {
            qDebug() << "File deleted successfully.";
        } else {
            qDebug() << "Failed to delete the file.";
        }
    } else {
        qDebug() << "File does not exist.";
    }
}


void CameraView::keyPressEvent(QKeyEvent *event)
{
    // 仅在全屏状态下响应 Esc 键关闭事件
    if (isFullScreen() && event->key() == Qt::Key_Escape) {
        close();  // 全屏时按 Esc 键关闭窗口
    } else {
        QWidget::keyPressEvent(event);  // 处理其他按键事件
    }
}
