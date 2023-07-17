#pragma once
#include <thread>
#include <cmath>
#include <vector>
#include "Buckets.h"
class RegionGenerator {
public:
    //Empty constructor
    RegionGenerator() {}
    /*
    function create array with buckets and calculte coordinates of each bucket
    each bucket is with size full Hd '/' sqrt of number of threads.Bucket array is created horizontally
    */
    void generateCoordinates(const int& imageHeight, const int& imageWidth,const int& numberOfThreads) {
        int regionHeight = imageHeight / static_cast<int>(std::sqrt(numberOfThreads));
        int regionWidth = imageWidth / static_cast<int>(std::sqrt(numberOfThreads));

        int startX = 0;
        int endX = regionHeight;

        int startY = 0;
        int endY = 0;

        for (int i = 0; i < std::sqrt(numberOfThreads); ++i) {
            for (int j = 0; j < std::sqrt(numberOfThreads); ++j) {

                startY = endY;
                endY = endY + regionWidth;

                this->regions.emplace_back(Bucket(startX, endX, startY, endY));

            }
            startX = endX;
            endX = endX + regionHeight;
            startY = 0;
            endY = 0;
        }
    }
    std::vector<Bucket> getRegions() {
        return regions;
    }
private:
    std::vector<Bucket> regions;
};
