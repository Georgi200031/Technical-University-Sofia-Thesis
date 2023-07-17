#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_renderOptions.h"
#include "src/ColorRGB.h"
#include <QMessageBox>
#include <thread>
struct settings {
    int raysInPixel = 1;
    int maxRayDepth = 5;
    float FOV = 90;
    int GIRaysCount = 0;
};
struct optimizationsSettings {
    int bucketSize = 24;
    int accTreeDepth = 30;
    int maxBoxTrianglesCount = 15;
    int cpuThreadCount = std::thread::hardware_concurrency();
};
struct cameraSettings {
    float pan = 0.f;
    float roll = 0.f;
    float tilt = 0.f;
    float pedestal = 0.f;
    float truck = 0.f;
    float dolly = 0.f;
};
struct resolution {
public:
    void hd() {
        imageHeight = 720;
        imageWidth = 1280;
    }
    void fullHd() {
        imageHeight = 1080;
        imageWidth = 1920;
    }
    void fourK() {
        imageHeight = 2160;
        imageWidth = 3840;
    }
    int imageHeight = 1080;
    int imageWidth = 1920;
    
};
class renderOptions : public QMainWindow
{
    Q_OBJECT

public:
    renderOptions(QWidget* parent = Q_NULLPTR);
    /*
        functions for optimizations and settings 
    */
    void handleOptimizationButton();
    void handleSaveSettingsButtonClick();
    void handleSaveOptimizationButtonClick();
    void handleSettingsButton();
    void controlSettingsButton(bool action);
    void controlOptimizationButton(bool action);
    void controlCameraButton(bool action);
    void handleCameraClick();
    void handleSaveCameraClick();
    void handleHdResolution();
    void handleFullHdResolution();
    void handleFourKResolution();

    resolution resolutionImage;
    settings setting;
    optimizationsSettings optimizationSetting;
    cameraSettings cameraSetting;
    bool isRenderedPicture = false;
    QSize previousWindowSize = size();

private:
    bool setStringFloat(QString& string, float& settings, QTextEdit& text);
    bool setStringInt(QString& string, int& settings, QTextEdit& text);
    Ui::MainWindow ui;
};
