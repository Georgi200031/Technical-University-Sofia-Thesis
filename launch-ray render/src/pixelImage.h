#pragma once
#include <vector>
#include "ColorRGB.h"
#include <fstream>
/*
class implement final image of the render
*/
class PixelImage {
public:
    //Constructor which set image pixels,image Buffer and fileName
    PixelImage(const int& imageHeight, const int& imageWidth, std::vector<std::vector<ColorRGB>>& pixelMatrix, const std::string& filename) :
        imageHeight(imageHeight), imageWidth(imageWidth), pixelMatrix(pixelMatrix), filename(filename) {}
    /*
    this function give image Buffer and write it in PPM file
    */
	void writeToPpm() {
        std::ofstream ppmFileStream("samples/" + filename + ".ppm", std::ios::out | std::ios::binary);
        ppmFileStream << "P3\n";
        ppmFileStream << imageWidth << " " << imageHeight << "\n";
        ppmFileStream << maxColorComponent << "\n";
        //here overwrite pixelMatrix into ppmFileStream
        for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
            for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
                ppmFileStream << pixelMatrix[rowIdx][colIdx].R << " "
                    << pixelMatrix[rowIdx][colIdx].G << " "
                    << pixelMatrix[rowIdx][colIdx].B << newTab;
            }
            ppmFileStream << newLine;
        }
	}
private:
    int imageHeight;
    int imageWidth;
    std::vector<std::vector<ColorRGB>>& pixelMatrix;
    std::string filename;
};