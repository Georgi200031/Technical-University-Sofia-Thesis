/********************************************************************************
** Form generated from reading UI file 'renderOptions.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDEROPTIONS_H
#define UI_RENDEROPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSettings;
    QAction *actionOptimizations;
    QAction *actioncamera;
    QAction *actionimage_settings;
    QAction *actionHD;
    QAction *actionFull_Hd;
    QAction *action4K;
    QWidget *centralwidget;
    QPushButton *saveSettingsButton;
    QLabel *samplesRayInPixelLabel;
    QTextEdit *samplesRayInPixelText;
    QLabel *maxRayDepthLabel;
    QTextEdit *maxRayDepthText;
    QLabel *fovLabel;
    QTextEdit *fovText;
    QLabel *giRaysCountLabel;
    QTextEdit *giRaysCountText;
    QLabel *bucketSizeLabel;
    QLabel *accThreeDepthLabel;
    QLabel *maxBoxTrianglesCountLabel;
    QTextEdit *bucketSizeText;
    QTextEdit *accThreeDepthText;
    QTextEdit *maxBoxTrianglesCountText;
    QPushButton *saveOptimizationsButton;
    QLabel *cpuThreadsLabel;
    QTextEdit *cpuThreadCountText;
    QLabel *numberThreads;
    QLabel *cameraPanLabel;
    QLabel *cameraRollLabel;
    QLabel *cameraTiltLabel;
    QLabel *cameraPedestalLabel;
    QLabel *CameraTruckLabel;
    QLabel *cameraDollyLabel;
    QTextEdit *cameraPanText;
    QTextEdit *cameraRollText;
    QTextEdit *cameraTiltText;
    QTextEdit *cameraPedestalText;
    QTextEdit *cameraTruckText;
    QTextEdit *cameraDollyText;
    QPushButton *saveCameraButton;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuResolutions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(198, 439);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName("actionSettings");
        actionOptimizations = new QAction(MainWindow);
        actionOptimizations->setObjectName("actionOptimizations");
        actioncamera = new QAction(MainWindow);
        actioncamera->setObjectName("actioncamera");
        actionimage_settings = new QAction(MainWindow);
        actionimage_settings->setObjectName("actionimage_settings");
        actionHD = new QAction(MainWindow);
        actionHD->setObjectName("actionHD");
        actionFull_Hd = new QAction(MainWindow);
        actionFull_Hd->setObjectName("actionFull_Hd");
        action4K = new QAction(MainWindow);
        action4K->setObjectName("action4K");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        saveSettingsButton = new QPushButton(centralwidget);
        saveSettingsButton->setObjectName("saveSettingsButton");
        saveSettingsButton->setGeometry(QRect(40, 340, 111, 24));
        samplesRayInPixelLabel = new QLabel(centralwidget);
        samplesRayInPixelLabel->setObjectName("samplesRayInPixelLabel");
        samplesRayInPixelLabel->setGeometry(QRect(10, -10, 151, 31));
        samplesRayInPixelText = new QTextEdit(centralwidget);
        samplesRayInPixelText->setObjectName("samplesRayInPixelText");
        samplesRayInPixelText->setGeometry(QRect(10, 20, 111, 21));
        maxRayDepthLabel = new QLabel(centralwidget);
        maxRayDepthLabel->setObjectName("maxRayDepthLabel");
        maxRayDepthLabel->setGeometry(QRect(10, 40, 151, 31));
        maxRayDepthText = new QTextEdit(centralwidget);
        maxRayDepthText->setObjectName("maxRayDepthText");
        maxRayDepthText->setGeometry(QRect(10, 70, 111, 21));
        fovLabel = new QLabel(centralwidget);
        fovLabel->setObjectName("fovLabel");
        fovLabel->setGeometry(QRect(10, 90, 151, 31));
        fovText = new QTextEdit(centralwidget);
        fovText->setObjectName("fovText");
        fovText->setGeometry(QRect(10, 120, 111, 21));
        giRaysCountLabel = new QLabel(centralwidget);
        giRaysCountLabel->setObjectName("giRaysCountLabel");
        giRaysCountLabel->setGeometry(QRect(10, 140, 151, 31));
        giRaysCountText = new QTextEdit(centralwidget);
        giRaysCountText->setObjectName("giRaysCountText");
        giRaysCountText->setGeometry(QRect(10, 170, 111, 21));
        bucketSizeLabel = new QLabel(centralwidget);
        bucketSizeLabel->setObjectName("bucketSizeLabel");
        bucketSizeLabel->setGeometry(QRect(10, 0, 81, 16));
        accThreeDepthLabel = new QLabel(centralwidget);
        accThreeDepthLabel->setObjectName("accThreeDepthLabel");
        accThreeDepthLabel->setGeometry(QRect(10, 50, 131, 16));
        maxBoxTrianglesCountLabel = new QLabel(centralwidget);
        maxBoxTrianglesCountLabel->setObjectName("maxBoxTrianglesCountLabel");
        maxBoxTrianglesCountLabel->setGeometry(QRect(10, 100, 121, 16));
        bucketSizeText = new QTextEdit(centralwidget);
        bucketSizeText->setObjectName("bucketSizeText");
        bucketSizeText->setGeometry(QRect(10, 20, 111, 21));
        accThreeDepthText = new QTextEdit(centralwidget);
        accThreeDepthText->setObjectName("accThreeDepthText");
        accThreeDepthText->setGeometry(QRect(10, 70, 111, 21));
        maxBoxTrianglesCountText = new QTextEdit(centralwidget);
        maxBoxTrianglesCountText->setObjectName("maxBoxTrianglesCountText");
        maxBoxTrianglesCountText->setGeometry(QRect(10, 120, 111, 21));
        saveOptimizationsButton = new QPushButton(centralwidget);
        saveOptimizationsButton->setObjectName("saveOptimizationsButton");
        saveOptimizationsButton->setGeometry(QRect(40, 340, 111, 24));
        cpuThreadsLabel = new QLabel(centralwidget);
        cpuThreadsLabel->setObjectName("cpuThreadsLabel");
        cpuThreadsLabel->setGeometry(QRect(10, 150, 141, 16));
        cpuThreadCountText = new QTextEdit(centralwidget);
        cpuThreadCountText->setObjectName("cpuThreadCountText");
        cpuThreadCountText->setGeometry(QRect(10, 170, 111, 21));
        numberThreads = new QLabel(centralwidget);
        numberThreads->setObjectName("numberThreads");
        numberThreads->setGeometry(QRect(150, 150, 49, 16));
        cameraPanLabel = new QLabel(centralwidget);
        cameraPanLabel->setObjectName("cameraPanLabel");
        cameraPanLabel->setGeometry(QRect(10, 0, 91, 16));
        cameraRollLabel = new QLabel(centralwidget);
        cameraRollLabel->setObjectName("cameraRollLabel");
        cameraRollLabel->setGeometry(QRect(10, 50, 81, 16));
        cameraTiltLabel = new QLabel(centralwidget);
        cameraTiltLabel->setObjectName("cameraTiltLabel");
        cameraTiltLabel->setGeometry(QRect(10, 100, 91, 16));
        cameraPedestalLabel = new QLabel(centralwidget);
        cameraPedestalLabel->setObjectName("cameraPedestalLabel");
        cameraPedestalLabel->setGeometry(QRect(10, 150, 111, 16));
        CameraTruckLabel = new QLabel(centralwidget);
        CameraTruckLabel->setObjectName("CameraTruckLabel");
        CameraTruckLabel->setGeometry(QRect(10, 200, 81, 16));
        cameraDollyLabel = new QLabel(centralwidget);
        cameraDollyLabel->setObjectName("cameraDollyLabel");
        cameraDollyLabel->setGeometry(QRect(10, 250, 91, 16));
        cameraPanText = new QTextEdit(centralwidget);
        cameraPanText->setObjectName("cameraPanText");
        cameraPanText->setGeometry(QRect(10, 20, 111, 21));
        cameraRollText = new QTextEdit(centralwidget);
        cameraRollText->setObjectName("cameraRollText");
        cameraRollText->setGeometry(QRect(10, 70, 111, 21));
        cameraTiltText = new QTextEdit(centralwidget);
        cameraTiltText->setObjectName("cameraTiltText");
        cameraTiltText->setGeometry(QRect(10, 120, 111, 21));
        cameraPedestalText = new QTextEdit(centralwidget);
        cameraPedestalText->setObjectName("cameraPedestalText");
        cameraPedestalText->setGeometry(QRect(10, 170, 111, 21));
        cameraTruckText = new QTextEdit(centralwidget);
        cameraTruckText->setObjectName("cameraTruckText");
        cameraTruckText->setGeometry(QRect(10, 220, 111, 21));
        cameraDollyText = new QTextEdit(centralwidget);
        cameraDollyText->setObjectName("cameraDollyText");
        cameraDollyText->setGeometry(QRect(10, 270, 111, 21));
        saveCameraButton = new QPushButton(centralwidget);
        saveCameraButton->setObjectName("saveCameraButton");
        saveCameraButton->setGeometry(QRect(40, 340, 111, 24));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 198, 22));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName("menuSettings");
        menuResolutions = new QMenu(menuBar);
        menuResolutions->setObjectName("menuResolutions");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuResolutions->menuAction());
        menuSettings->addAction(actionSettings);
        menuSettings->addAction(actionOptimizations);
        menuSettings->addAction(actioncamera);
        menuSettings->addSeparator();
        menuResolutions->addAction(actionHD);
        menuResolutions->addAction(actionFull_Hd);
        menuResolutions->addAction(action4K);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "settings", nullptr));
        actionOptimizations->setText(QCoreApplication::translate("MainWindow", "optimizations", nullptr));
        actioncamera->setText(QCoreApplication::translate("MainWindow", "camera", nullptr));
        actionimage_settings->setText(QCoreApplication::translate("MainWindow", "image settings", nullptr));
        actionHD->setText(QCoreApplication::translate("MainWindow", "HD", nullptr));
        actionFull_Hd->setText(QCoreApplication::translate("MainWindow", "Full Hd", nullptr));
        action4K->setText(QCoreApplication::translate("MainWindow", "4K", nullptr));
        saveSettingsButton->setText(QCoreApplication::translate("MainWindow", "save setttings", nullptr));
        samplesRayInPixelLabel->setText(QCoreApplication::translate("MainWindow", "Samples Ray In Pixel", nullptr));
        samplesRayInPixelText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", nullptr));
        maxRayDepthLabel->setText(QCoreApplication::translate("MainWindow", "Max ray Depth", nullptr));
        maxRayDepthText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5</p></body></html>", nullptr));
        fovLabel->setText(QCoreApplication::translate("MainWindow", "FOV", nullptr));
        fovText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">90</p></body></html>", nullptr));
        giRaysCountLabel->setText(QCoreApplication::translate("MainWindow", "GI Rays Count", nullptr));
        giRaysCountText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", nullptr));
        bucketSizeLabel->setText(QCoreApplication::translate("MainWindow", "Bucket Size", nullptr));
        accThreeDepthLabel->setText(QCoreApplication::translate("MainWindow", "Acceleration Tree depth", nullptr));
        maxBoxTrianglesCountLabel->setText(QCoreApplication::translate("MainWindow", "maxBoxTrianglesCount", nullptr));
        bucketSizeText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">24</p></body></html>", nullptr));
        accThreeDepthText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">30</p></body></html>", nullptr));
        maxBoxTrianglesCountText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">15</p></body></html>", nullptr));
        saveOptimizationsButton->setText(QCoreApplication::translate("MainWindow", "save optimizations", nullptr));
        cpuThreadsLabel->setText(QCoreApplication::translate("MainWindow", "CPU Threads Your System", nullptr));
        cpuThreadCountText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4</p></body></html>", nullptr));
        numberThreads->setText(QString());
        cameraPanLabel->setText(QCoreApplication::translate("MainWindow", "camera pan", nullptr));
        cameraRollLabel->setText(QCoreApplication::translate("MainWindow", "camera roll", nullptr));
        cameraTiltLabel->setText(QCoreApplication::translate("MainWindow", "camera tilt", nullptr));
        cameraPedestalLabel->setText(QCoreApplication::translate("MainWindow", "camera pedestal", nullptr));
        CameraTruckLabel->setText(QCoreApplication::translate("MainWindow", "camera truck", nullptr));
        cameraDollyLabel->setText(QCoreApplication::translate("MainWindow", "camera dolly", nullptr));
        cameraPanText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        saveCameraButton->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuResolutions->setTitle(QCoreApplication::translate("MainWindow", "Resolutions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDEROPTIONS_H
