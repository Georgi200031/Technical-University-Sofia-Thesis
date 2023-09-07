#include "launchrayrender.h"
#include "ui_launchrayrender.h"
#include <QBuffer>
#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>
#include <QtWidgets/QApplication>
#include "src/SceneParser.h"
#include "src/moveObject.h"
#include <QCommandLineParser>
#include <QDebug>
#include <chrono>
#include <QFileDialog>
#include <QProcess>
#include <iostream>
#include <string>

using namespace std::chrono;

launchrayrender::launchrayrender(QWidget* parent)
    : QMainWindow(parent) 
{
    ui.setupUi(this); 
    image = QImage(renderSettings.resolutionImage.imageWidth, renderSettings.resolutionImage.imageHeight, QImage::Format_RGB888); // Initialize the pixel buffer

    connect(ui.actionACC_Tree_AABB_with_Bucket_rendering, &QAction::triggered, this, &launchrayrender::handelACCTreeMode);
    connect(ui.actionAABB_with_Bucket_rendering, &QAction::triggered, this, &launchrayrender::handelAABBwithBucketMode);
    connect(ui.actionBucket_rendering_only, &QAction::triggered, this, &launchrayrender::handelBucketRenderingMode);
    connect(ui.actionRegion_rendering, &QAction::triggered, this, &launchrayrender::handelRegionRenderingMode);
    connect(ui.openScene, &QAction::triggered, this, &launchrayrender::handleFileClick);
    connect(ui.saveFrame, &QAction::triggered, this, &launchrayrender::handleFileSaveFrame);
    connect(ui.virRenderTime, &QAction::triggered, this, &launchrayrender::handleRenderTimeClick);
    //connect(ui.actionopen_settings_panel, &QAction::triggered, this, &launchrayrender::openSettingsPanel);
    update();
}
void launchrayrender::handleRenderTimeClick() {
    if (pixelMatrix.empty()) {
        QMessageBox::information(nullptr, "Error", "Error not rendering scene");
    }
    else {
        timerUI.show();
    }
}
void launchrayrender::handleFileClick() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("All Files (*.crtscene)"));

    if (!filePath.isEmpty()) {
        inputFilePath = filePath.toStdString();
    }
}
void launchrayrender::handleFileSaveFrame() {
    // Your existing code...
    if (pixelMatrix.empty()) {
        QMessageBox::information(nullptr, "Error", "Error not rendering scene");
    }
    else {
        // Create a QImage from the pixelMatrix
        QImage image(pixelMatrix[0].size(), pixelMatrix.size(), QImage::Format_RGB888);
        for (int y = 0; y < pixelMatrix.size(); ++y)
        {
            for (int x = 0; x < pixelMatrix[y].size(); ++x)
            {
                const ColorRGB& color = pixelMatrix[y][x];
                image.setPixelColor(x, y, QColor(color.R, color.G, color.B));
            }
        }

        // Save the image as a PNG file
        QString savePath = QFileDialog::getSaveFileName(this, tr("Save Image"), QDir::homePath(), tr("PNG Files (*.png)"));
        if (!savePath.isEmpty())
        {
            if (!image.save(savePath, "PNG"))
            {
                QMessageBox::information(nullptr, "Error", "Is not png");
            }
        }
    }
}
void launchrayrender::loadImage(std::vector<std::vector<ColorRGB>> pixelMatrix) {
    this->pixelMatrix = pixelMatrix;
}

void launchrayrender::handelACCTreeMode() {
    if (inputFilePath.empty()) {
            QMessageBox::information(nullptr, "Error", "Error not input scene");
    }
    else
        handelRenderingMode(MultithreadingMode::KDTree);
}

void launchrayrender::handelAABBwithBucketMode() {
    if (inputFilePath.empty()) {
        QMessageBox::information(nullptr, "Error", "Error not input scene");
    }
    else
    handelRenderingMode(MultithreadingMode::AABBox);
}

void launchrayrender::handelBucketRenderingMode() {
    if (inputFilePath.empty()) {
        QMessageBox::information(nullptr, "Error", "Error not input scene");
    }
    else
    handelRenderingMode(MultithreadingMode::BucketRendering);
}

void launchrayrender::handelRegionRenderingMode() {
    if (inputFilePath.empty()) {
        QMessageBox::information(nullptr, "Error", "Error not input scene");
    }
    else
    handelRenderingMode(MultithreadingMode::RegionRendering);
}

void launchrayrender::handelRenderingMode(MultithreadingMode renderingMode)
{
    high_resolution_clock::time_point frameStart = high_resolution_clock::now();
    // Load parser
    SceneParser parseScene{ this->inputFilePath };
    Scene3d parsedScene;
    parseScene.loadScene3d(parsedScene);
    Render render;

    render.settings.rayInPixel = renderSettings.setting.raysInPixel;
    render.settings.maxRayDepth = renderSettings.setting.maxRayDepth;
    render.settings.GIRaysCount = renderSettings.setting.GIRaysCount;
    render.settings.bucketSize = renderSettings.optimizationSetting.bucketSize;
    render.settings.accTreeDepth = renderSettings.optimizationSetting.accTreeDepth;
    render.settings.maxBoxTrianglesCount = renderSettings.optimizationSetting.maxBoxTrianglesCount;
    render.settings.cpuThreadsCount = renderSettings.optimizationSetting.cpuThreadCount;
    render.settings.imageHeight = renderSettings.resolutionImage.imageHeight;
    render.settings.imageWidth = renderSettings.resolutionImage.imageWidth;
    parsedScene.getCamera().FOV(this->renderSettings.setting.FOV);
    parsedScene.getCamera().pan(this->renderSettings.cameraSetting.pan);
    parsedScene.getCamera().roll(this->renderSettings.cameraSetting.roll);
    parsedScene.getCamera().tilt(this->renderSettings.cameraSetting.tilt);
    parsedScene.getCamera().pedestal(this->renderSettings.cameraSetting.pedestal);
    parsedScene.getCamera().truck(this->renderSettings.cameraSetting.truck);
    parsedScene.getCamera().dolly(this->renderSettings.cameraSetting.dolly);


    this->renderSettings.isRenderedPicture = false;
    render.pixelMatrix = this->pixelMatrix;
    render.rendering(render, parsedScene, ("frame" + std::to_string(0)), renderingMode);

    high_resolution_clock::time_point frameEnd = high_resolution_clock::now();
    microseconds frameDuration = duration_cast<microseconds>(frameEnd - frameStart);
    double frameSeconds = frameDuration.count() / 1000000.0; 
    timerUI.setRenderTime(frameSeconds);

    loadImage(render.pixelMatrix); 
    update();
}
void launchrayrender::openSettingsPanel() {
    renderSettings.show();
}

void launchrayrender::paintEvent(QPaintEvent* event)
{
    renderSettings.show();
    if (pixelMatrix.size() != 0) {
        if (this->renderSettings.isRenderedPicture == false || size() != this->renderSettings.previousWindowSize ) {
            this->renderSettings.isRenderedPicture = true;
            this->renderSettings.previousWindowSize = size();
            QMainWindow::paintEvent(event);

            // Create a QPixmap buffer to draw the pixels on
            
            QPixmap bufferN(size());
            // Create a QPainter and set the pen color to red
            QPainter painter(&bufferN); // Use the buffer for painting

            // Calculate the size and position of each pixel based on the window size
            const int numPixelsX = width();
            const int numPixelsY = height();
            const int imageWidth = pixelMatrix[0].size();
            const int imageHeight = pixelMatrix.size();
            const int pixelSizeX = width() / numPixelsX;
            const int pixelSizeY = height() / numPixelsY;

            // Calculate the visible region based on the event
            QRect visibleRect = event->rect();

            // Generate pixels within the visible region using a loop
            for (int i = 0; i < numPixelsY; i++)
            {
                int y = i * pixelSizeY;

                for (int j = 0; j < numPixelsX; j++)
                {
                    int x = j * pixelSizeX;

                    // Calculate the corresponding position in the pixelMatrix
                    int pixelMatrixX = j * imageWidth / numPixelsX;
                    int pixelMatrixY = i * imageHeight / numPixelsY;

                    QColor penColor(pixelMatrix[pixelMatrixY][pixelMatrixX].R,
                        pixelMatrix[pixelMatrixY][pixelMatrixX].G,
                        pixelMatrix[pixelMatrixY][pixelMatrixX].B);

                    painter.setPen(penColor);
                    QRect pixelRect(x, y, pixelSizeX, pixelSizeY);

                    // Check if the pixel is within the visible region
                    if (visibleRect.intersects(pixelRect))
                    {
                        painter.drawRect(pixelRect);
                    }
                }
            }
            // Create a QPainter for the widget and draw the buffer onto it
            QPainter widgetPainter(this);
            widgetPainter.drawPixmap(0, 0, bufferN.scaled(size()));
            this->buffer = bufferN;
            update();
        }
        else {
            QPainter widgetPainter(this);
            widgetPainter.drawPixmap(0, 0, buffer.scaled(size()));
            update();
        }
    }
}
void launchrayrender::closeEvent(QCloseEvent* event) {
    renderSettings.close();
}