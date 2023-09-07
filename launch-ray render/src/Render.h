#pragma once
#include "ColorRGB.h"
#include "Scene3d.h"
#include <vector>
#include <iostream>
#include <thread>
#include <limits>
#include <fstream>
#include "Vector3d.h"
#include "AccTreeNode.h"
#include "KdTree.h"
#include "Buckets.h"
#include <QTimer>
#include "renderSettings.h"
#include "../launchrayrender.h"
#include "../renderTime.h"

class bucketGenerator;

//Bucket structore store coordinates of regions

class Render{
public:
    renderSettings settings;

    std::vector<std::vector<ColorRGB>> pixelMatrix;
    //first check what optimzing algorithm use(release,Region Rendering,bucket Rendering or Axis Aligned Bounding Box)
    //And the end store image Buffer (pixelMatrix) in ppm file
    void rendering( Render& render, const Scene3d& sceneOne,const  std::string& filename,const MultithreadingMode& mMode);
    //renderRegion() divides the screen into parts and use each threads to calculate it.
    void renderRegion(const Bucket& bucket,  std::vector<std::vector<ColorRGB>>& pixelMatrix);

    Scene3d scene;
    //if object material have smoothShading
      //if object material is diffuse return color by shading with hitNormal
      //if object material is reflective create reflective ray and with that ray (rayTrace) it until the color is returned
    //if object material have not smoothShading 
      //function return color by shading function with triangleIntersectNormal
    Vector3d shade(const Ray& ray, intersectionData& intersectInfo);

    //Trace the given ray into the scene and determine colour at intersection point (if any). 
    //if have no intersection, returns
    //the background colour.
    //Recursively traces new rays into the scene uppon hitting a reflective material. 
    //if depth is reach (5 rays) return background
    intersectionData rayTrace( Ray& ray, float maxT = std::numeric_limits<float>::max());

    //function return ColorRGB after ray hit diffuse material    
    Vector3d shadeDiffuse(const Ray& ray,  intersectionData& intersectInfo);
    //function return ColorRGB after ray hit reflective material
    Vector3d shadeReflective(const Ray& ray,  intersectionData& intersectInfo);
    //function return ColorRGB after ray hit refractive material
    Vector3d shadeRefractive(const Ray& ray,  intersectionData& intersectInfo);
    
    
    std::vector<AccTreeNode> accTree;
    renderOptions renderSettings;
    KdTree kdtree;
    MultithreadingMode mthreadMode = MultithreadingMode::invalid;
    int rays;
};
