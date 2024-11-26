#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cameraview.h"
#include <QMainWindow>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    // 自定义标题栏按钮槽
    void onMinimizeClicked();
    void onMaximizeRestoreClicked();
    void onCloseClicked();

protected:
    // 重写鼠标事件，用于支持窗口拖动
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;

    QPoint mousePressPosition;  // 鼠标按下时的位置
    bool isMaximized = false;   // 是否处于最大化状态

    std::vector<CameraView*> cameras;
};

#endif // MAINWINDOW_H
