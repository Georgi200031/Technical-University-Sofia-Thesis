#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_launchrayrender.h"
#include "renderOptions.h"
#include "renderTime.h"
#include "src/renderSettings.h"
class launchrayrender : public QMainWindow
{
    Q_OBJECT

public:
    
    launchrayrender(QWidget *parent = Q_NULLPTR) ;
    void loadImage(std::vector<std::vector<ColorRGB>> pixelMatrix);

    void paintEvent(QPaintEvent* event);
    void closeEvent(QCloseEvent* event);
    void openSettingsPanel();
    void handelACCTreeMode();
    void handelAABBwithBucketMode();
    void handelBucketRenderingMode();
    void handelRegionRenderingMode();
    void handleFileClick();
    void handleFileSaveFrame();
    void handleRenderTimeClick();
    void handelRenderingMode(MultithreadingMode renderingMode);
    //Rendering renderingScene;
private:
    QPixmap buffer; 
    std::string inputFilePath;
    renderOptions renderSettings;
    int rowIdx;
    int colIdx;
    renderTime timerUI;
    Ui::launchrayrenderClass ui;
    QImage image; // Pixel buffer for storing the rendered image
    std::vector<std::vector<ColorRGB>> pixelMatrix;
};
