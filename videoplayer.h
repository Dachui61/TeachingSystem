#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QVideoWidget>
#include <QPushButton>
#include <QListView>
#include <QFileSystemModel>
#include <QFile>
#include <QProgressBar>
#include <QMediaPlayer>
#include <QSlider>
#include <QGroupBox>
class videoPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit videoPlayer(QWidget *parent = nullptr);
    ~videoPlayer();

private:

    QVideoWidget* videoWidget;
    QMediaPlayer* mediaPlayer;
    QGroupBox* groupBox_play;
    QGroupBox* groupBox_Btn;
    QSlider* slider;
    QPushButton* btn_prev;
    QPushButton* btn_next;
    QPushButton* btn_startOrStop;
    QListView* listView;
    QFileSystemModel * fileSystemModel;

    void setUi();
    void bindViewModel(QListView* view, QFileSystemModel* model);
    void setStyle();

private slots:
    void selectedVideo(const QModelIndex &index);
    void updateSlider(qint64 position);
    void setSliderRange(qint64 duration);
    void startOrStopPlay();
    void playPrev();
    void playNext();

};

#endif // VIDEOPLAYER_H
