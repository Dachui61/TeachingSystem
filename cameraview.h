#ifndef CAMERAVIEW_H
#define CAMERAVIEW_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QContextMenuEvent>
#include <QKeyEvent>
#include "HCNetSDK.h"

enum class slotName
{
    startRecordingSlot,
    stopRecordingSlot,
    viewHistorySlot
};

namespace Ui {
class CameraView;
}

class CameraView : public QWidget
{
    Q_OBJECT

public:
    CameraView(QWidget *parent = nullptr);
    // 新的构造函数，接受设备参数
    CameraView(const QString& ip, int port, const QString& username, const QString& password,
               int lChannel, int dwStreamType, int dwLinkMode, int bBlocked , QWidget *parent = nullptr);
    CameraView(const QString& ip, int port, const QString& username, const QString& password, QWidget *parent = nullptr);
    ~CameraView();
    void do_slots(slotName sName);  // 根据 slotName 调用不同的槽函数

signals:
    void switchToMain(CameraView* widget);
    void startRecording(CameraView* widget);
    void stopRecording(CameraView* widget);
    void viewHistory(CameraView* widget);

private slots:
    void showContextMenu(const QPoint &pos);
    void startRecordingSlot();
    void stopRecordingSlot();
    void viewHistorySlot();  // 取消注释并实现槽函数

private:
    QLabel *videoLabel;
    QTimer *timer;
    LONG lUserID;
    LONG lRealPlayHandle;
    bool isRecording;
    QString recordSavePath;
    QString videoFileName;

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;  // 添加键盘事件
    void convertVideo(const QString &inputFile, const QString &outputFile);

};

#endif // CAMERAVIEW_H
