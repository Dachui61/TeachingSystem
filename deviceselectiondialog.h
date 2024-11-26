#ifndef DEVICESELECTIONDIALOG_H
#define DEVICESELECTIONDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "HoverableListWidget.h"
#include "devicesmgr.h"

class DeviceSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceSelectionDialog(QWidget *parent = nullptr);
    ~DeviceSelectionDialog();

signals:
    void deviceSelected(const Device &device); // 信号，用于发送选择的设备信息

private slots:
    void onDeviceClicked();                // 设备选择按钮点击槽函数
    void onItemHovered(QListWidgetItem *item); // 鼠标悬浮槽函数

private:
    HoverableListWidget *deviceListWidget; // 悬浮检测的设备列表
    QLabel *detailsLabel;                  // 显示设备详细信息
    QPushButton *closeButton;              // 关闭按钮
};

#endif // DEVICESELECTIONDIALOG_H
