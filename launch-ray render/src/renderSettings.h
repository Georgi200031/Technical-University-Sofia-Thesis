#pragma once

enum MultithreadingMode {
    invalid,
    Release,
    RegionRendering,
    BucketRendering,
    AABBox,
    KDTree
};
class renderSettings {
public:
    /* settings */
    int rayInPixel = 1;
    int maxRayDepth = 5;
    float FOV = 45;
    int GIRaysCount = 0;

    /* optimizations settings */
    int bucketSize=24;
    int accTreeDepth=30;
    int maxBoxTrianglesCount=15;
    int cpuThreadsCount=4;

    int imageHeight;
    int imageWidth;
};
