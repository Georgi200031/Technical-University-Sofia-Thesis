/********************************************************************************
** Form generated from reading UI file 'renderTime.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERTIME_H
#define UI_RENDERTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_renderTime
{
public:
    QLabel *renderLabel;
    QLabel *time;
    QLabel *label;

    void setupUi(QWidget *renderTime)
    {
        if (renderTime->objectName().isEmpty())
            renderTime->setObjectName("renderTime");
        renderTime->resize(274, 118);
        renderLabel = new QLabel(renderTime);
        renderLabel->setObjectName("renderLabel");
        renderLabel->setGeometry(QRect(20, 30, 121, 51));
        time = new QLabel(renderTime);
        time->setObjectName("time");
        time->setGeometry(QRect(130, 50, 49, 16));
        label = new QLabel(renderTime);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 50, 49, 16));

        retranslateUi(renderTime);

        QMetaObject::connectSlotsByName(renderTime);
    } // setupUi

    void retranslateUi(QWidget *renderTime)
    {
        renderTime->setWindowTitle(QCoreApplication::translate("renderTime", "Form", nullptr));
        renderLabel->setText(QCoreApplication::translate("renderTime", "Was Rendered in ", nullptr));
        time->setText(QString());
        label->setText(QCoreApplication::translate("renderTime", "seconds", nullptr));
    } // retranslateUi

};

namespace Ui {
    class renderTime: public Ui_renderTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERTIME_H
