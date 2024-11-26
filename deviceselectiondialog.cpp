#include "DeviceSelectionDialog.h"
#include <QDebug>

DeviceSelectionDialog::DeviceSelectionDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("设备选择");
    setMinimumSize(400, 300);

    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 使用 HoverableListWidget
    deviceListWidget = new HoverableListWidget(this);
    deviceListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // 创建设备详情显示区域
    detailsLabel = new QLabel("悬浮在设备上以查看详情", this);
    detailsLabel->setStyleSheet("border: 1px solid #ccc; padding: 5px; background-color: #f9f9f9;");
    detailsLabel->setMinimumHeight(100);

    // 创建关闭按钮
    closeButton = new QPushButton("关闭", this);

    // 添加到主布局
    mainLayout->addWidget(deviceListWidget);
    mainLayout->addWidget(detailsLabel);
    mainLayout->addWidget(closeButton);

    // 从设备管理器加载设备列表
    auto devicesMgr = DevicesMgr::GetInstance();
    auto devices = devicesMgr->getDevices();
    for (const auto &device : devices) {
        QListWidgetItem *item = new QListWidgetItem(device.ip, deviceListWidget);
        item->setData(Qt::UserRole, QVariant::fromValue(device)); // 存储设备信息到 UserRole
    }

    // 连接信号槽
    connect(deviceListWidget, &HoverableListWidget::itemHovered, this, &DeviceSelectionDialog::onItemHovered);
    connect(deviceListWidget, &QListWidget::itemClicked, this, &DeviceSelectionDialog::onDeviceClicked);
    connect(closeButton, &QPushButton::clicked, this, &DeviceSelectionDialog::close);
}

DeviceSelectionDialog::~DeviceSelectionDialog() = default;

// 点击设备按钮
void DeviceSelectionDialog::onDeviceClicked()
{
    QListWidgetItem *currentItem = deviceListWidget->currentItem();
    if (currentItem) {
        const Device device = currentItem->data(Qt::UserRole).value<Device>();
        emit deviceSelected(device); // 发送设备选择信号
        qDebug() << "Selected Device:" << device.ip;
    }
    close();
}

// 鼠标悬浮槽函数
void DeviceSelectionDialog::onItemHovered(QListWidgetItem *item)
{
    if (item) {
        const Device device = item->data(Qt::UserRole).value<Device>();
        detailsLabel->setText(
            QString("IP: %1\n端口: %2\n用户名: %3\n通道: %4")
                .arg(device.ip)
                .arg(device.port)
                .arg(device.username)
                .arg(device.lChannel));
    } else {
        detailsLabel->setText("悬浮在设备上以查看详情");
    }
}
