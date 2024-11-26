/********************************************************************************
** Form generated from reading UI file 'comparisondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPARISONDIALOG_H
#define UI_COMPARISONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComparisonDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *main_widget;
    QHBoxLayout *horizontalLayout;
    QWidget *left_widget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *LCamwidget;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *RCamwidget;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *ComparisonDialog)
    {
        if (ComparisonDialog->objectName().isEmpty())
            ComparisonDialog->setObjectName("ComparisonDialog");
        ComparisonDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ComparisonDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        main_widget = new QWidget(ComparisonDialog);
        main_widget->setObjectName("main_widget");
        horizontalLayout = new QHBoxLayout(main_widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        left_widget = new QWidget(main_widget);
        left_widget->setObjectName("left_widget");
        verticalLayout_3 = new QVBoxLayout(left_widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 127, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        LCamwidget = new QWidget(left_widget);
        LCamwidget->setObjectName("LCamwidget");
        LCamwidget->setMinimumSize(QSize(0, 0));

        verticalLayout_3->addWidget(LCamwidget);

        verticalSpacer_2 = new QSpacerItem(20, 127, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(left_widget);

        widget_2 = new QWidget(main_widget);
        widget_2->setObjectName("widget_2");
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 127, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        RCamwidget = new QWidget(widget_2);
        RCamwidget->setObjectName("RCamwidget");
        RCamwidget->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(RCamwidget);

        verticalSpacer_4 = new QSpacerItem(20, 127, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout->addWidget(widget_2);


        verticalLayout->addWidget(main_widget);


        retranslateUi(ComparisonDialog);

        QMetaObject::connectSlotsByName(ComparisonDialog);
    } // setupUi

    void retranslateUi(QDialog *ComparisonDialog)
    {
        ComparisonDialog->setWindowTitle(QCoreApplication::translate("ComparisonDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComparisonDialog: public Ui_ComparisonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPARISONDIALOG_H
