#ifndef CAMERAVIEW_H
#define CAMERAVIEW_H

#include <QWidget>

namespace Ui {
class CameraView;
}

class CameraView : public QWidget
{
    Q_OBJECT

public:
    explicit CameraView(QWidget *parent = nullptr);
    ~CameraView();

private:
    Ui::CameraView *ui;
};

#endif // CAMERAVIEW_H
