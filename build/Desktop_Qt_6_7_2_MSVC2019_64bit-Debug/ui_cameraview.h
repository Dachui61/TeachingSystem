/********************************************************************************
** Form generated from reading UI file 'cameraview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAVIEW_H
#define UI_CAMERAVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraView
{
public:

    void setupUi(QWidget *CameraView)
    {
        if (CameraView->objectName().isEmpty())
            CameraView->setObjectName("CameraView");
        CameraView->resize(400, 300);

        retranslateUi(CameraView);

        QMetaObject::connectSlotsByName(CameraView);
    } // setupUi

    void retranslateUi(QWidget *CameraView)
    {
        CameraView->setWindowTitle(QCoreApplication::translate("CameraView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraView: public Ui_CameraView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAVIEW_H
