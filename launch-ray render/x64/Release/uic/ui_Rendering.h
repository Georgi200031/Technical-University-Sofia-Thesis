/********************************************************************************
** Form generated from reading UI file 'Rendering.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERING_H
#define UI_RENDERING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rendering
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *rendering)
    {
        if (rendering->objectName().isEmpty())
            rendering->setObjectName("rendering");
        rendering->resize(355, 200);
        centralwidget = new QWidget(rendering);
        centralwidget->setObjectName("centralwidget");
        rendering->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(rendering);
        statusbar->setObjectName("statusbar");
        rendering->setStatusBar(statusbar);

        retranslateUi(rendering);

        QMetaObject::connectSlotsByName(rendering);
    } // setupUi

    void retranslateUi(QMainWindow *rendering)
    {
        rendering->setWindowTitle(QCoreApplication::translate("rendering", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rendering: public Ui_rendering {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERING_H
