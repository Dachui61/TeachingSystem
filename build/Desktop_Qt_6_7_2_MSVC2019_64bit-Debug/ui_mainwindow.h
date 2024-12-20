/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <cameraview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *right_workspace;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    CameraView *main_view;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer_3;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_6;
    QWidget *left_bar;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *play_btn;
    QPushButton *stop_btn;
    QPushButton *pause_btn;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(768, 500);
        MainWindow->setMinimumSize(QSize(750, 500));
        MainWindow->setMaximumSize(QSize(768, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(0, 500));
        widget_3->setMaximumSize(QSize(16777215, 500));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        right_workspace = new QWidget(widget_3);
        right_workspace->setObjectName("right_workspace");
        verticalLayout_3 = new QVBoxLayout(right_workspace);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(right_workspace);
        widget_5->setObjectName("widget_5");
        widget_5->setMinimumSize(QSize(0, 330));
        widget_5->setMaximumSize(QSize(16777215, 330));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName("widget_2");
        verticalLayout_7 = new QVBoxLayout(widget_2);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(15);
        label_2->setFont(font);
        label_2->setTextFormat(Qt::TextFormat::AutoText);
        label_2->setScaledContents(false);

        verticalLayout_7->addWidget(label_2);

        main_view = new CameraView(widget_2);
        main_view->setObjectName("main_view");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(main_view->sizePolicy().hasHeightForWidth());
        main_view->setSizePolicy(sizePolicy);
        main_view->setMinimumSize(QSize(490, 276));
        main_view->setMaximumSize(QSize(490, 276));

        verticalLayout_7->addWidget(main_view);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);


        horizontalLayout_3->addWidget(widget_2);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName("widget_4");
        widget_4->setMinimumSize(QSize(200, 0));
        widget_4->setMaximumSize(QSize(200, 16777215));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName("widget_8");
        widget_8->setMinimumSize(QSize(0, 300));
        widget_8->setMaximumSize(QSize(16777215, 300));
        verticalLayout_5 = new QVBoxLayout(widget_8);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_3 = new QLabel(widget_8);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(label_3);

        widget_6 = new QWidget(widget_8);
        widget_6->setObjectName("widget_6");
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton = new QPushButton(widget_6);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_6);
        pushButton_2->setObjectName("pushButton_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout_5->addWidget(widget_6);

        label_4 = new QLabel(widget_8);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 25));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(label_4);

        widget_7 = new QWidget(widget_8);
        widget_7->setObjectName("widget_7");
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButton_3 = new QPushButton(widget_7);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_7);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(pushButton_4);


        verticalLayout_5->addWidget(widget_7);


        verticalLayout_6->addWidget(widget_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);


        horizontalLayout_3->addWidget(widget_4);


        verticalLayout_3->addWidget(widget_5);

        listWidget = new QListWidget(right_workspace);
        listWidget->setObjectName("listWidget");
        listWidget->setMinimumSize(QSize(100, 130));
        listWidget->setMaximumSize(QSize(16777215, 130));
        listWidget->setSpacing(0);

        verticalLayout_3->addWidget(listWidget);

        verticalSpacer_6 = new QSpacerItem(20, 37, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);


        horizontalLayout_2->addWidget(right_workspace);

        left_bar = new QWidget(widget_3);
        left_bar->setObjectName("left_bar");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(left_bar->sizePolicy().hasHeightForWidth());
        left_bar->setSizePolicy(sizePolicy3);
        left_bar->setMinimumSize(QSize(60, 500));
        left_bar->setMaximumSize(QSize(80, 500));
        verticalLayout_2 = new QVBoxLayout(left_bar);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(left_bar);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 100));
        label->setMaximumSize(QSize(16777215, 100));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        widget = new QWidget(left_bar);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        play_btn = new QPushButton(widget);
        play_btn->setObjectName("play_btn");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(play_btn->sizePolicy().hasHeightForWidth());
        play_btn->setSizePolicy(sizePolicy4);
        play_btn->setMinimumSize(QSize(45, 45));
        play_btn->setMaximumSize(QSize(45, 45));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/start.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        play_btn->setIcon(icon);
        play_btn->setIconSize(QSize(50, 50));
        play_btn->setFlat(true);

        verticalLayout->addWidget(play_btn);

        stop_btn = new QPushButton(widget);
        stop_btn->setObjectName("stop_btn");
        stop_btn->setMinimumSize(QSize(45, 45));
        stop_btn->setMaximumSize(QSize(45, 45));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/stop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stop_btn->setIcon(icon1);
        stop_btn->setIconSize(QSize(45, 45));
        stop_btn->setFlat(true);

        verticalLayout->addWidget(stop_btn);

        pause_btn = new QPushButton(widget);
        pause_btn->setObjectName("pause_btn");
        pause_btn->setMinimumSize(QSize(45, 45));
        pause_btn->setMaximumSize(QSize(45, 45));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/pause.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pause_btn->setIcon(icon2);
        pause_btn->setIconSize(QSize(45, 45));
        pause_btn->setAutoDefault(false);
        pause_btn->setFlat(true);

        verticalLayout->addWidget(pause_btn);


        verticalLayout_2->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 205, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(left_bar);


        horizontalLayout->addWidget(widget_3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        pause_btn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\270\273\347\225\214\351\235\242\345\261\225\347\244\272\344\270\255", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\217\347\211\271\345\206\231\345\261\225\347\244\272", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\225\231\345\270\210", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\257\271\346\257\224\345\261\225\347\244\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\345\270\210/\347\224\237", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237/\345\255\246\347\224\237", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\212\237\350\203\275\345\214\272", nullptr));
        play_btn->setText(QString());
        stop_btn->setText(QString());
        pause_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
