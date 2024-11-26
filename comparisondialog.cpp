#include "comparisondialog.h"
#include "cameraview.h"
#include "devicesmgr.h"
#include "ui_comparisondialog.h"

ComparisonDialog::ComparisonDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ComparisonDialog)
{
    ui->setupUi(this);

    auto devicesMgr = DevicesMgr::GetInstance();
    const auto& devices = devicesMgr->getDevices();
    if (devices.empty()) {
        qDebug() << "No devices available.";
        return;
    }

    const auto& dev = devices[0];

    // 创建右侧的 CameraView
    CameraView *rightCamView = new CameraView(dev.ip, dev.port, dev.username, dev.password, this);
    rightCamView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    rightCamView->setMinimumSize(600, 450); // 设置最小宽高为3:4比例 (300宽, 225高)

    // 将右侧的 CameraView 添加到布局中
    QVBoxLayout *rLayout = qobject_cast<QVBoxLayout*>(ui->RCamwidget->layout());
    if (!rLayout) {
        rLayout = new QVBoxLayout(ui->RCamwidget);
        ui->RCamwidget->setLayout(rLayout);
    }
    rLayout->addWidget(rightCamView);

    // 创建左侧的 CameraView
    CameraView *leftCamView = new CameraView(this);
    leftCamView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    leftCamView->setMinimumSize(600, 450); // 设置最小宽高为3:4比例

    // 将左侧的 CameraView 添加到布局中
    QVBoxLayout *lLayout = qobject_cast<QVBoxLayout*>(ui->LCamwidget->layout());
    if (!lLayout) {
        lLayout = new QVBoxLayout(ui->LCamwidget);
        ui->LCamwidget->setLayout(lLayout);
    }
    lLayout->addWidget(leftCamView);

    // 调整父窗口布局，使 CameraView 自动调整大小
    adjustSize();
}


ComparisonDialog::~ComparisonDialog()
{
    delete ui;
}


void ComparisonDialog::keyPressEvent(QKeyEvent *event)
{
    // 仅在全屏状态下响应 Esc 键关闭事件
    if (isFullScreen() && event->key() == Qt::Key_Escape) {
        close();  // 全屏时按 Esc 键关闭窗口
    } else {
        QWidget::keyPressEvent(event);  // 处理其他按键事件
    }
}
