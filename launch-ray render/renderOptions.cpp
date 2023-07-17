#include "renderOptions.h"
#include "ui_renderOptions.h"
#include <QPushButton>
#include <iostream>
#include <string>

#include <QDebug>
#include <QMessageBox>
renderOptions::renderOptions(QWidget* parent)
    : QMainWindow(parent)
{
    Qt::WindowFlags flags = windowFlags();
    flags &= ~Qt::WindowMaximizeButtonHint;
    setWindowFlags(flags);

    ui.setupUi(this);
    controlOptimizationButton(false);
    controlCameraButton(false);
    connect(ui.saveSettingsButton, &QPushButton::clicked, this, &renderOptions::handleSaveSettingsButtonClick);
    connect(ui.saveOptimizationsButton, &QPushButton::clicked, this, &renderOptions::handleSaveOptimizationButtonClick);
    connect(ui.saveCameraButton, &QPushButton::clicked, this, &renderOptions::handleSaveCameraClick);
    connect(ui.actionHD, &QAction::triggered, this, &renderOptions::handleHdResolution);
    connect(ui.actionFull_Hd, &QAction::triggered, this, &renderOptions::handleFullHdResolution);
    connect(ui.action4K, &QAction::triggered, this, &renderOptions::handleFourKResolution);
    connect(ui.actioncamera, &QAction::triggered, this, &renderOptions::handleCameraClick);
    connect(ui.actionSettings, &QAction::triggered, this, &renderOptions::handleSettingsButton);
    connect(ui.actionOptimizations, &QAction::triggered, this, &renderOptions::handleOptimizationButton);
    update();
}

void renderOptions::handleHdResolution() {
    resolutionImage.hd();
}

void renderOptions::handleFullHdResolution() {
    resolutionImage.fullHd();
}

void renderOptions::handleFourKResolution() {
    resolutionImage.fourK();
}

void renderOptions::controlSettingsButton(bool action) {
    ui.maxRayDepthLabel->setVisible(action);
    ui.samplesRayInPixelLabel->setVisible(action);
    ui.giRaysCountLabel->setVisible(action);
    ui.fovLabel->setVisible(action);
    ui.fovText->setVisible(action);
    ui.giRaysCountText->setVisible(action);
    ui.samplesRayInPixelText->setVisible(action);
    ui.maxRayDepthText->setVisible(action);
    ui.saveSettingsButton->setVisible(action);
}
void renderOptions::controlOptimizationButton(bool action) {
    ui.bucketSizeLabel->setVisible(action);
    ui.bucketSizeText->setVisible(action);
    ui.accThreeDepthLabel->setVisible(action);
    ui.accThreeDepthText->setVisible(action);
    ui.maxBoxTrianglesCountLabel->setVisible(action);
    ui.maxBoxTrianglesCountText->setVisible(action);
    ui.cpuThreadsLabel->setVisible(action);
    ui.cpuThreadCountText->setVisible(action);
    ui.numberThreads->setVisible(action);
    ui.numberThreads->setText(QString::number(std::thread::hardware_concurrency()));
    ui.saveOptimizationsButton->setVisible(action);
}

void renderOptions::controlCameraButton(bool action) {
    ui.cameraPanLabel->setVisible(action);
    ui.cameraPanText->setVisible(action);
    ui.cameraRollLabel->setVisible(action);
    ui.cameraRollText->setVisible(action);
    ui.cameraTiltLabel->setVisible(action);
    ui.cameraTiltText->setVisible(action);
    ui.cameraPedestalLabel->setVisible(action);
    ui.cameraPedestalText->setVisible(action);
    ui.CameraTruckLabel->setVisible(action);
    ui.cameraTruckText->setVisible(action);
    ui.cameraDollyLabel->setVisible(action);
    ui.cameraDollyText->setVisible(action);
    ui.saveCameraButton->setVisible(action);
}

void renderOptions::handleOptimizationButton() {
    controlCameraButton(false);
    controlSettingsButton(false);
    controlOptimizationButton(true);
}
void renderOptions::handleSettingsButton() {
    controlCameraButton(false);
    controlOptimizationButton(false);
    controlSettingsButton(true);
}
void renderOptions::handleCameraClick() {
    controlCameraButton(true);
    controlOptimizationButton(false);
    controlSettingsButton(false);
}

bool renderOptions::setStringFloat(QString& string, float& settings, QTextEdit& text) {
    bool isNumber;
    settings = string.toFloat(&isNumber);
    if (string.isEmpty())
        return true;
    if (!isNumber || settings < -360 || settings > 360) {
        text.setText("");
        return false;
    }
}

bool renderOptions::setStringInt(QString& string, int& settings, QTextEdit& text) {
    bool isNumber;
    settings = string.toFloat(&isNumber);
    if (string.isEmpty() || !isNumber || settings < 0 ) {
        text.setText("");
        return false;
    }
}

void renderOptions::handleSaveCameraClick() {
    bool checkValidInformations = true;
    QString cameraPan = ui.cameraPanText->toPlainText();
    checkValidInformations = setStringFloat(cameraPan, this->cameraSetting.pan, *ui.cameraPanText);

    QString cameraRoll = ui.cameraRollText->toPlainText();
    checkValidInformations = setStringFloat(cameraRoll, this->cameraSetting.roll, *ui.cameraRollText);

    QString cameraTilt = ui.cameraTiltText->toPlainText();
    checkValidInformations = setStringFloat(cameraTilt, this->cameraSetting.tilt, *ui.cameraTiltText);

    QString cameraPedestal = ui.cameraPedestalText->toPlainText();
    checkValidInformations = setStringFloat(cameraPedestal, this->cameraSetting.pedestal, *ui.cameraPedestalText);

    QString cameraTruck = ui.cameraTruckText->toPlainText();
    checkValidInformations = setStringFloat(cameraTruck, this->cameraSetting.truck, *ui.cameraTruckText);

    QString cameraDolly = ui.cameraDollyText->toPlainText();
    checkValidInformations = setStringFloat(cameraDolly, this->cameraSetting.dolly, *ui.cameraDollyText);
    
    if (checkValidInformations == false) {
        QMessageBox::information(nullptr, "Error", "Error input information");
    }
}
void renderOptions::handleSaveSettingsButtonClick()
{
    bool validInformaions = true;
    QString sRaysInPixel = ui.samplesRayInPixelText->toPlainText();
    validInformaions = setStringInt(sRaysInPixel, this->setting.raysInPixel, *ui.samplesRayInPixelText);

    QString mRayDepth = ui.maxRayDepthText->toPlainText();
    validInformaions = setStringInt(mRayDepth, this->setting.maxRayDepth, *ui.maxRayDepthText);

    QString FOV = ui.fovText->toPlainText();
    validInformaions = setStringFloat(FOV, this->setting.FOV, *ui.fovText);

    QString GI = ui.giRaysCountText->toPlainText();
    validInformaions = setStringInt(GI, this->setting.GIRaysCount, *ui.giRaysCountText);

    if (validInformaions == false) {
        QMessageBox::information(nullptr, "Error", "Error input information");
    }
}
void renderOptions::handleSaveOptimizationButtonClick() {
    bool checkValidInformations = true;

    QString bucketSize = ui.bucketSizeText->toPlainText();
    checkValidInformations = setStringInt(bucketSize, this->optimizationSetting.bucketSize, *ui.bucketSizeText);

    QString accTreeDepth = ui.accThreeDepthText->toPlainText();
    checkValidInformations = setStringInt(bucketSize, this->optimizationSetting.accTreeDepth, *ui.accThreeDepthText);

    QString maxTriangleCount = ui.maxBoxTrianglesCountText->toPlainText();
    checkValidInformations = setStringInt(bucketSize, this->optimizationSetting.maxBoxTrianglesCount, *ui.maxBoxTrianglesCountText);

    QString cpuThreadsCount = ui.cpuThreadCountText->toPlainText();
    checkValidInformations = setStringInt(bucketSize, this->optimizationSetting.cpuThreadCount, *ui.cpuThreadCountText);

    if (checkValidInformations == false) {
        QMessageBox::information(nullptr, "Error", "Error input information");
    }
}