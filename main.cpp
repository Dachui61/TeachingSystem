#include "mainwindow.h"
#include "qpushbutton.h"
#include <QDir>
#include <QApplication>


// #include "devicesmgr.h"
// #include "singleton.h"
// #include <iostream>

// int main() {
//     auto devicesMgr = DevicesMgr::GetInstance();
//     const auto& devices = devicesMgr->getDevices();
//     const auto& dev = devices[0];
//     for (const auto& device : devices) {
//         std::cout << "Device IP: " << device.ip.toStdString()
//         << ", Port: " << device.port << std::endl;
//     }

//     return 0;
// }


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    w.setWindowTitle("示教系统");             // 设置窗口标题
    w.setWindowIcon(QIcon(":/img/logo.png")); // 设置窗口图标，确保路径正确
    return a.exec();
}
