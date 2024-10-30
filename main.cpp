#include "mainwindow.h"
#include "qpushbutton.h"
#include <QDir>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("示教系统");             // 设置窗口标题
    w.setWindowIcon(QIcon(":/img/logo.png")); // 设置窗口图标，确保路径正确
    return a.exec();
}
