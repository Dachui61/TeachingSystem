#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // menuBar()->hide();   // 隐藏菜单栏
    // statusBar()->hide();  // 隐藏状态栏

    // 创建 QListView
    QListView* listView = ui->listView;
    listView->setFlow(QListView::LeftToRight); // 设置列表项从左到右布局
    listView->setWrapping(false); // 禁止换行，这样才能实现横向滚动
    listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // 显示水平滚动条
    listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 隐藏垂直滚动条

    // 创建一个 QStandardItemModel
    QStandardItemModel *model = new QStandardItemModel(listView);

    // 设置图像路径
    QString imagePath = ":/img/jsdemo.jpg"; // 确保图像路径正确

    // 计算项的大小，保持16:9的比例
    int itemHeight = listView->height(); // 获取 QListView 的高度
    int itemWidth = itemHeight * 16 / 9; // 根据 16:9 的比例计算宽度

    // 生成 10 个 item
    for (int i = 0; i < 10; ++i) {
        QStandardItem *item = new QStandardItem();

        // 设置项的图标为图片
        item->setIcon(QIcon(imagePath));
        item->setText(QString::number(i+1));
        item->setFlags(item->flags() & ~Qt::ItemIsEditable); // 设置为不可编辑

        // 设置项的大小提示
        item->setSizeHint(QSize(itemWidth, itemHeight)); // 设置项的大小
        model->appendRow(item); // 将项添加到模型
    }

    // 将模型设置到 QListView
    listView->setModel(model);

    // 设置 QListView 的图标大小
    listView->setIconSize(QSize(itemWidth, itemHeight)); // 设置图标大小与项大小一致

    // 显示 QListView
    listView->resize(300, 400);
    listView->show();

    // 加载 QSS 文件
    QFile file(":/qss/styleSheet.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);  // 正确调用 setStyleSheet
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // 创建 CameraView 并设置为全屏
    CameraView* camview = new CameraView();
    camview->setAttribute(Qt::WA_DeleteOnClose);  // 关闭时自动删除
    camview->showFullScreen();  // 显示为全屏
}

