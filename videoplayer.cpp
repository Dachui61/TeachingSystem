#include "videoplayer.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QVideoWidget>
#include <QPushButton>
#include <QListView>
#include <QFileSystemModel>
#include <QFile>
#include <QProgressBar>
#include <QGroupBox>
#include <QCoreApplication>
#include <QAudioOutput>
#include <QSlider>
#include <QMediaPlayer>
videoPlayer::videoPlayer(QWidget *parent)
    : QWidget{parent}
{
    listView = new QListView();
    fileSystemModel = new QFileSystemModel(listView);
    videoWidget = new QVideoWidget();
    QAudioOutput* audioOutput = new QAudioOutput(this);
    mediaPlayer = new QMediaPlayer();
    slider = new QSlider(Qt::Horizontal);
    btn_prev = new QPushButton();
    btn_next = new QPushButton();
    btn_startOrStop = new QPushButton();

    mediaPlayer->setVideoOutput(videoWidget);
    mediaPlayer->setAudioOutput(audioOutput);

    setUi();
    setStyle();

    connect(listView, &QListView::clicked, this, &videoPlayer::selectedVideo);
    connect(btn_startOrStop, &QPushButton::clicked, this, &videoPlayer::startOrStopPlay);
    connect(btn_prev, &QPushButton::clicked, this, &videoPlayer::playPrev);
    connect(btn_next, &QPushButton::clicked, this, &videoPlayer::playNext);


    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &videoPlayer::updateSlider);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &videoPlayer::setSliderRange);

    connect(mediaPlayer, &QMediaPlayer::playbackStateChanged, this, [=](){qDebug()<<mediaPlayer->playbackState();
    });
}

videoPlayer::~videoPlayer()
{

}

void videoPlayer::setUi()
{

    QHBoxLayout* playAndListLayout = new QHBoxLayout(this);

    groupBox_play = new QGroupBox();
    bindViewModel(listView, fileSystemModel);
    playAndListLayout->addWidget(groupBox_play, 85);
    playAndListLayout->addWidget(listView, 15);

    QVBoxLayout* playBoxLayout = new QVBoxLayout(groupBox_play);
    groupBox_Btn = new QGroupBox();
    playBoxLayout->addWidget(videoWidget);
    playBoxLayout->addWidget(slider);
    playBoxLayout->addWidget(groupBox_Btn);

    QHBoxLayout* btnLayout = new QHBoxLayout(groupBox_Btn);
    groupBox_Btn->setMaximumHeight(60);
    btnLayout->addWidget(btn_prev);
    btnLayout->addWidget(btn_startOrStop);
    btnLayout->addWidget(btn_next);

    this->setLayout(playAndListLayout);
}

void videoPlayer::setStyle()
{
    QString style = "QGroupBox { background-color: white; }";
    groupBox_play->setStyleSheet(style);

    style = "QPushButton {"
                    "background-color: transparent;;"
                    "}";
    btn_startOrStop->setStyleSheet(style);
    btn_prev->setStyleSheet(style);
    btn_next->setStyleSheet(style);
    btn_startOrStop->setFixedSize(40, 40);
    btn_prev->setFixedSize(40, 40);
    btn_next->setFixedSize(40, 40);
    // btn_startOrStop->setIcon(QIcon(":/icon/C:/Users/Liao/Downloads/start.png"));
    // btn_prev->setIcon(QIcon(":/icon/C:/Users/Liao/Downloads/prev.png"));
    // btn_next->setIcon(QIcon(":/icon/C:/Users/Liao/Downloads/next.png"));
    btn_startOrStop->setIconSize(QSize(40,40));
    btn_prev->setIconSize(QSize(40,40));
    btn_next->setIconSize(QSize(40,40));
}
void videoPlayer::bindViewModel(QListView *view, QFileSystemModel *model)
{
    QString path = QCoreApplication::applicationDirPath() + "/savedVideo";
    QModelIndex rootIndex = model->setRootPath(path);  // 设置根目录路径
    view->setModel(model);
    view->setRootIndex(rootIndex);  // 确保视图从该根目录开始显示
}

void videoPlayer::updateSlider(qint64 position)
{
    slider->setValue(static_cast<int>(position));
}

void videoPlayer::setSliderRange(qint64 duration)
{
    slider->setRange(0, static_cast<int>(duration));
}

void videoPlayer::startOrStopPlay()
{
    if (mediaPlayer->playbackState() == QMediaPlayer::PlayingState){
        mediaPlayer->pause();
        // btn_startOrStop->setIcon(QIcon(":/icon/C:/Users/Liao/Downloads/stop.png"));
    }else if (mediaPlayer->playbackState() == QMediaPlayer::PausedState){
        mediaPlayer->play();
        // btn_startOrStop->setIcon(QIcon(":/icon/C:/Users/Liao/Downloads/start.png"));
    }
}

void videoPlayer::playPrev()
{
    QModelIndex currentIndex = listView->currentIndex();
    qDebug()<<fileSystemModel->filePath(currentIndex);
    QModelIndex previousIndex = fileSystemModel->index(currentIndex.row() - 1, 0, currentIndex.parent());
    qDebug()<<fileSystemModel->filePath(previousIndex);

    if (previousIndex.isValid()) {
        QString filePath = fileSystemModel->filePath(previousIndex);
        QFileInfo fileInfo(filePath);
        listView->setCurrentIndex(previousIndex);
        if (fileInfo.exists() && fileInfo.isFile()) {
            mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
            mediaPlayer->play();
        } else {
            qDebug() << "Selected file is not a valid video format.";
        }
    } else {
        qDebug() << "No previous item available.";
    }
}

void videoPlayer::playNext()
{
    QModelIndex currentIndex = listView->currentIndex();
    qDebug()<<fileSystemModel->filePath(currentIndex);
    QModelIndex nextIndex = fileSystemModel->index(currentIndex.row() + 1, 0, currentIndex.parent());
    qDebug()<<fileSystemModel->filePath(nextIndex);

    if (nextIndex.isValid()) {
        QString filePath = fileSystemModel->filePath(nextIndex);
        QFileInfo fileInfo(filePath);
        listView->setCurrentIndex(nextIndex);
        if (fileInfo.exists() && fileInfo.isFile()) {
            mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
            mediaPlayer->play();
        } else {
            qDebug() << "Selected file is not a valid video format.";
        }
    } else {
        qDebug() << "No previous item available.";
    }
}

void videoPlayer::selectedVideo(const QModelIndex &index)
{
    QString filePath = fileSystemModel->filePath(index);

    if (QFile::exists(filePath)) {
        mediaPlayer->setSource(QUrl::fromLocalFile(filePath));
        mediaPlayer->play();
    } else {
        qDebug() << "File does not exist!";
    }
}
