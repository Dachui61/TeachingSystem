#include "mainwindow.h"
#include "comparisondialog.h"
#include "devicesmgr.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QFile>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置无边框窗口
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 创建自定义标题栏
    QWidget *titleBar = new QWidget(this);
    titleBar->setStyleSheet("background-color: #444; color: white;");
    titleBar->setFixedHeight(40);

    QLabel *titleLabel = new QLabel("智慧示教系统", titleBar);
    titleLabel->setStyleSheet("font-size: 14px; padding-left: 10px;");

    QPushButton *minimizeButton = new QPushButton("-", titleBar);
    QPushButton *maximizeButton = new QPushButton("□", titleBar);
    //隐藏最大化
    maximizeButton->hide();
    QPushButton *closeButton = new QPushButton("×", titleBar);

    // 设置按钮样式
    minimizeButton->setStyleSheet("color: white; background-color: transparent; border: none; font-size: 25px;");
    maximizeButton->setStyleSheet("color: white; background-color: transparent; border: none; font-size: 25px;");
    closeButton->setStyleSheet("color: white; background-color: transparent; border: none; font-size: 25px;");

    // 信号槽连接
    connect(minimizeButton, &QPushButton::clicked, this, &MainWindow::onMinimizeClicked);
    connect(maximizeButton, &QPushButton::clicked, this, &MainWindow::onMaximizeRestoreClicked);
    connect(closeButton, &QPushButton::clicked, this, &MainWindow::onCloseClicked);

    // 标题栏布局
    QHBoxLayout *titleLayout = new QHBoxLayout(titleBar);
    titleLayout->addWidget(titleLabel);
    titleLayout->addStretch();
    titleLayout->addWidget(minimizeButton);
    titleLayout->addWidget(maximizeButton);
    titleLayout->addWidget(closeButton);
    titleLayout->setContentsMargins(0, 0, 0, 0);
    titleBar->setLayout(titleLayout);

    // 添加标题栏到主布局
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(titleBar);
    mainLayout->addWidget(ui->centralwidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    QWidget *central = new QWidget(this);
    central->setLayout(mainLayout);
    this->setCentralWidget(central);

    // 配置 QListWidget
    QListWidget* listWidget = ui->listWidget;
    listWidget->setFlow(QListView::LeftToRight); // 设置列表项从左到右布局
    listWidget->setWrapping(false); // 禁止换行，这样才能实现横向滚动
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // 显示水平滚动条
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 隐藏垂直滚动条

    // 设置项的大小
    int itemHeight = ui->listWidget->height();
    int itemWidth = itemHeight * 4 / 3;

    // 创建并添加 CameraView 小部件
    auto devicesmgr = DevicesMgr::GetInstance();
    auto devices = devicesmgr->getDevices();
    for (int i = 0; i < devices.size(); ++i) {
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(itemWidth, itemHeight));
        // 从配置文件中读取
        CameraView *cameraView = new CameraView(devices[i].ip, devices[i].port, devices[i].username,
                                                devices[i].password, devices[i].lChannel, devices[i].dwStreamType, devices[i].dwLinkMode, devices[i].bBlocked);
        // CameraView *cameraView = new CameraView("10.16.41.20", 8001, "admin", "cqupt2210", 1, 0, 0, 1);
        if(cameraView == nullptr) continue;
        cameras.push_back(cameraView);
        cameraView->setStyleSheet("border: 1px solid black;");
        listWidget->addItem(item);
        listWidget->setItemWidget(item, cameraView);

    }
    listWidget->setSpacing(5);
    listWidget->setCurrentItem(nullptr);
    listWidget->update();
    listWidget->repaint();

    // 加载 QSS 样式文件
    QFile file(":/qss/styleSheet.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    CameraView* camview = new CameraView();
    camview->setAttribute(Qt::WA_DeleteOnClose);
    camview->showFullScreen();
}

void MainWindow::on_pushButton_2_clicked()
{
    auto devicesMgr = DevicesMgr::GetInstance();
    const auto& devices = devicesMgr->getDevices();
    const auto& dev = devices[0];
    CameraView* camview = new CameraView(dev.ip, dev.port, dev.username, dev.password);
    if(camview != nullptr) {
        camview->setAttribute(Qt::WA_DeleteOnClose);
        camview->showFullScreen();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ComparisonDialog* comview = new ComparisonDialog();
    if(comview != nullptr) {
        comview->setAttribute(Qt::WA_DeleteOnClose);
        comview->showFullScreen();
    }
}

void MainWindow::onMinimizeClicked()
{
    this->showMinimized();
}

void MainWindow::onMaximizeRestoreClicked()
{
    if (isMaximized) {
        this->showNormal();
        isMaximized = false;
    } else {
        this->showMaximized();
        isMaximized = true;
    }
}

void MainWindow::onCloseClicked()
{
    this->close();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mousePressPosition = event->globalPos() - this->frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        this->move(event->globalPos() - mousePressPosition);
        event->accept();
    }
}
