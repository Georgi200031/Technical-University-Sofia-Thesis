/********************************************************************************
** Form generated from reading UI file 'launchrayrender.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHRAYRENDER_H
#define UI_LAUNCHRAYRENDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_launchrayrenderClass
{
public:
    QAction *actionVersion_0_1_Beta;
    QAction *openScene;
    QAction *saveFrame;
    QAction *virRenderTime;
    QAction *actionRegion_rendering;
    QAction *actionBucket_rendering_only;
    QAction *actionAABB_with_Bucket_rendering;
    QAction *actionACC_Tree_AABB_with_Bucket_rendering;
    QWidget *centralWidget;
    QFrame *frame;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *RenderButton;
    QMenu *menurender_mode;
    QMenu *menuVersion;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *launchrayrenderClass)
    {
        if (launchrayrenderClass->objectName().isEmpty())
            launchrayrenderClass->setObjectName("launchrayrenderClass");
        launchrayrenderClass->resize(671, 533);
        actionVersion_0_1_Beta = new QAction(launchrayrenderClass);
        actionVersion_0_1_Beta->setObjectName("actionVersion_0_1_Beta");
        openScene = new QAction(launchrayrenderClass);
        openScene->setObjectName("openScene");
        saveFrame = new QAction(launchrayrenderClass);
        saveFrame->setObjectName("saveFrame");
        virRenderTime = new QAction(launchrayrenderClass);
        virRenderTime->setObjectName("virRenderTime");
        actionRegion_rendering = new QAction(launchrayrenderClass);
        actionRegion_rendering->setObjectName("actionRegion_rendering");
        actionBucket_rendering_only = new QAction(launchrayrenderClass);
        actionBucket_rendering_only->setObjectName("actionBucket_rendering_only");
        actionAABB_with_Bucket_rendering = new QAction(launchrayrenderClass);
        actionAABB_with_Bucket_rendering->setObjectName("actionAABB_with_Bucket_rendering");
        actionACC_Tree_AABB_with_Bucket_rendering = new QAction(launchrayrenderClass);
        actionACC_Tree_AABB_with_Bucket_rendering->setObjectName("actionACC_Tree_AABB_with_Bucket_rendering");
        centralWidget = new QWidget(launchrayrenderClass);
        centralWidget->setObjectName("centralWidget");
        frame = new QFrame(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(70, 60, 441, 281));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        launchrayrenderClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(launchrayrenderClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 671, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        RenderButton = new QMenu(menuBar);
        RenderButton->setObjectName("RenderButton");
        menurender_mode = new QMenu(RenderButton);
        menurender_mode->setObjectName("menurender_mode");
        menuVersion = new QMenu(menuBar);
        menuVersion->setObjectName("menuVersion");
        launchrayrenderClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(launchrayrenderClass);
        statusBar->setObjectName("statusBar");
        launchrayrenderClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(RenderButton->menuAction());
        menuBar->addAction(menuVersion->menuAction());
        menuFile->addAction(openScene);
        menuFile->addAction(saveFrame);
        RenderButton->addAction(menurender_mode->menuAction());
        RenderButton->addAction(virRenderTime);
        menurender_mode->addAction(actionRegion_rendering);
        menurender_mode->addAction(actionBucket_rendering_only);
        menurender_mode->addAction(actionAABB_with_Bucket_rendering);
        menurender_mode->addAction(actionACC_Tree_AABB_with_Bucket_rendering);
        menuVersion->addAction(actionVersion_0_1_Beta);

        retranslateUi(launchrayrenderClass);

        QMetaObject::connectSlotsByName(launchrayrenderClass);
    } // setupUi

    void retranslateUi(QMainWindow *launchrayrenderClass)
    {
        launchrayrenderClass->setWindowTitle(QCoreApplication::translate("launchrayrenderClass", "launchrayrender", nullptr));
        actionVersion_0_1_Beta->setText(QCoreApplication::translate("launchrayrenderClass", "Version 0.1 Beta", nullptr));
        openScene->setText(QCoreApplication::translate("launchrayrenderClass", "open scene", nullptr));
        saveFrame->setText(QCoreApplication::translate("launchrayrenderClass", "save frame", nullptr));
        virRenderTime->setText(QCoreApplication::translate("launchrayrenderClass", "view render time", nullptr));
        actionRegion_rendering->setText(QCoreApplication::translate("launchrayrenderClass", "Region rendering", nullptr));
        actionBucket_rendering_only->setText(QCoreApplication::translate("launchrayrenderClass", "Bucket rendering only", nullptr));
        actionAABB_with_Bucket_rendering->setText(QCoreApplication::translate("launchrayrenderClass", "AABB with Bucket rendering", nullptr));
        actionACC_Tree_AABB_with_Bucket_rendering->setText(QCoreApplication::translate("launchrayrenderClass", "ACC Tree AABB with Bucket rendering", nullptr));
        menuFile->setTitle(QCoreApplication::translate("launchrayrenderClass", "File", nullptr));
        RenderButton->setTitle(QCoreApplication::translate("launchrayrenderClass", "Render", nullptr));
        menurender_mode->setTitle(QCoreApplication::translate("launchrayrenderClass", "render mode", nullptr));
        menuVersion->setTitle(QCoreApplication::translate("launchrayrenderClass", "Version", nullptr));
    } // retranslateUi

};

namespace Ui {
    class launchrayrenderClass: public Ui_launchrayrenderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHRAYRENDER_H
