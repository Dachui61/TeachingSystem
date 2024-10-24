#include "cameraview.h"
#include "ui_cameraview.h"

CameraView::CameraView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CameraView)
{
    ui->setupUi(this);
}

CameraView::~CameraView()
{
    delete ui;
}
