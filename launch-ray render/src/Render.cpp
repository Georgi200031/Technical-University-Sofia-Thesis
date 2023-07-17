#pragma once
#include "Render.h"
#include "pixelImage.h"
#include "Region.h"
#include <mutex>
#include <algorithm>
#include <stack>
#include <algorithm>
#include <chrono>
using namespace std::chrono;

Vector3d Render::shadeDiffuse(const Ray& ray, intersectionData& data) {
   
    Vector3d finalColor;
    Vector3d& pointOnPlane = data.hitPoint;
    Vector3d& Normal = data.material->smoothShading ? data.hitPointNormal : data.triangleIntersectNormal;
    for (Lights3d& light : scene.getLights()) {

        Vector3d lightDirection = light.getPosition() - pointOnPlane;

        //Sphere radius
        float rad = lightDirection.length();
        //Normalise light direction
        lightDirection.normalize();
        float cos = std::max(0.0f, lightDirection.dot(Normal));

        Ray shadowRay{ pointOnPlane + Normal * SHADOW_BIAS, lightDirection, ray.depth, RayType::shadow };

        Vector3d triangleNormal;
        float maxT = rad;

        intersectionData shadowData = rayTrace(shadowRay, maxT);

        if (shadowData.intesectedTriInx == invalidIndexTriangle || shadowData.material->type == MaterialType::refractive) {
            //no intersection, i.e intesectedIndex = -1
            float sphereArea = 4 * PI * rad * rad;
            finalColor = finalColor + data.material->albedo * cos * ((light.getIntensity()) / sphereArea);
        }
    }

    if (scene.getSettings().getGiOn()) {
        Vector3d diffuseReflectionsColor(0, 0, 0);
        for (int diffuseReflectRayIndx = 0; diffuseReflectRayIndx < settings.GIRaysCount; diffuseReflectRayIndx++) {
            Vector3d rightAxis = ray.direction.cross(Normal);
            rightAxis.normalize();
            Vector3d upAxis = Normal;
            Vector3d forwardAxis = rightAxis.cross(upAxis);
            Matrix localHitMatrix(rightAxis.x, rightAxis.y, rightAxis.z,
                upAxis.x, upAxis.y, upAxis.z,
                forwardAxis.x, forwardAxis.y, forwardAxis.z);

            float  randAnglelnXY = PI * (std::rand() % 181) / 180.0f;

            Vector3d randVectorInXY = Vector3d(std::cosf(randAnglelnXY), std::sinf(randAnglelnXY), 0.f);
            float randAngleInXZ = 2.0f * PI * (std::rand() % 361) / 360.0f;

            Matrix rotateAroundY(
                std::cosf(randAngleInXZ), 0.f, -std::sinf(randAngleInXZ),
                0.f, 1.f, 0.f,
                std::sinf(randAngleInXZ), 0.f, std::cosf(randAngleInXZ)
            );
            Vector3d randVectorInXYRotated = rotateAroundY * randVectorInXY;
            Vector3d diffReflRayDir = localHitMatrix * randVectorInXYRotated;
            //diffReflRayDir.normalize();
            Vector3d diffRflRayOrigin = data.hitPoint + (Normal * HIT_RAY_BIAS);
            Ray diffReflRay = Ray(diffRflRayOrigin, diffReflRayDir, ray.depth + 1, RayType::shadow);
            intersectionData dataDiffRefl = rayTrace(diffReflRay);
    
            diffuseReflectionsColor = (diffuseReflectionsColor + shade(diffReflRay, dataDiffRefl));
        }
        diffuseReflectionsColor = diffuseReflectionsColor + finalColor;
       
        return (diffuseReflectionsColor) / (settings.GIRaysCount + 1);
    }
    else return finalColor;
}

Vector3d Render::shadeReflective(const Ray& ray, intersectionData& data) {
    Vector3d colorReflectedPixel;
    Ray reflectedRay = computeReflectedRay(ray,data.hitPoint, data.hitPointNormal,RayType::reflection);
    intersectionData reflectionData = rayTrace(reflectedRay);
    colorReflectedPixel = shade(reflectedRay,reflectionData);
    return scene.getSettings().getReflectionsOn() ? colorReflectedPixel * data.material->albedo : data.material->albedo;
}

Vector3d Render::shadeRefractive(const Ray& ray,  intersectionData& data) {
        float n1 = 1.f;   // refractive index of air
        float n2 = 1.5f;   // refractive index of sphere material (if have no ior set to 1.5 by default)
        Vector3d& N = data.material->smoothShading ? data.hitPointNormal : data.triangleIntersectNormal;
        float cosAlpha = std::clamp(1.f, -1.f, ray.direction.dot(N));
        if (cosAlpha > 0) {
            N = N * -1;
            std::swap(n2, n1);
        }
        else {
            cosAlpha = -1.f * cosAlpha;
        }

        float sinBeta = (n1 / n2) * sqrt(std::max(0.0f, 1.0f - cosAlpha * cosAlpha));
        float eta = (n1 / n2);
        if (sinBeta < 1) {
            Ray refractedRay = computeRefractiveRay(ray, data.hitPoint, N, sinBeta, cosAlpha,eta);
            intersectionData refractionData = rayTrace(refractedRay);
            Vector3d refractedColor = shade(refractedRay, refractionData);

            Ray reflectedRay = computeReflectedRay(ray, data.hitPoint, N, RayType::refraction);
            intersectionData reflectionData = rayTrace(reflectedRay);
            Vector3d reflectedColor = shade(reflectedRay, reflectionData);

            float R0 = ((n1 - n2) / (n1 + n2)) * ((n1 - n2) / (n1 + n2));
            float fresnel = R0 + (1.0f - R0) * pow(1.0f - cosAlpha, 5.0f);           
            return scene.getSettings().getRefractionsOn() ? reflectedColor * fresnel + refractedColor * (1.0f - fresnel) : refractionData.material->albedo;
        }
        else {
            Ray reflectedRay = computeReflectedRay(ray, data.hitPoint, N, RayType::refraction);
            intersectionData reflectionData = rayTrace(reflectedRay);
            return shade(reflectedRay, reflectionData);
        }
}

intersectionData Render::rayTrace(Ray& ray, float maxT)  {
    intersectionData data;
    if (mthreadMode == MultithreadingMode::KDTree) {
        data = kdtree.KdTreeAlgorithm(ray, maxT);
    }
    else {
        data.intesectedTriInx = scene.intersect(ray, data, maxT);
        if (data.intesectedTriInx != invalidIndexTriangle) {
            return data;
        }
    }
    return data;
}

Vector3d Render::shade(const Ray& ray,  intersectionData& data) {
    ColorRGB pixelColor;
    MaterialType hitMaterialType{ data.material == nullptr ? MaterialType::background : data.material->type };
    if (ray.depth >= settings.maxRayDepth) {
        return scene.getSettings().getBgColor();
    }
    if (MaterialType::diffuse == hitMaterialType) {
        return shadeDiffuse(ray, data);
    }
    else if (MaterialType::reflective == hitMaterialType) {
        return shadeReflective(ray, data);
    }
    else if (MaterialType::refractive == hitMaterialType) {
        return shadeRefractive(ray, data);
    }
    else if (MaterialType::constant == hitMaterialType) {
        return data.material->albedo;
    }
    return scene.getSettings().getBgColor();
}

//regionRendering
void Render::renderRegion(const Bucket& bucket, std::vector<std::vector<ColorRGB>>& pixelMatrix) {

    for (int rowIdx = bucket.startX; rowIdx < bucket.endX; ++rowIdx) {
        for (int colIdx = bucket.startY; colIdx < bucket.endY; ++colIdx) {
                for (int rays = 0; rays < settings.rayInPixel; rays++) {
                    Ray ray = generateCameraRay(colIdx, rowIdx, settings.imageWidth,
                        settings.imageHeight,
                        scene.getCamera(), scene.getCamera().getFovAngle());

                    intersectionData data = rayTrace(ray);
                    if (data.intesectedTriInx != invalidIndexTriangle) {
                        pixelMatrix[rowIdx][colIdx] = pixelMatrix[rowIdx][colIdx] + ColorRGB(shade(ray, data));
                    }
                    else {
                        pixelMatrix[rowIdx][colIdx] = pixelMatrix[rowIdx][colIdx] + ColorRGB(scene.getSettings().getBgColor());
                    }
                 }
                pixelMatrix[rowIdx][colIdx] = ColorRGB(pixelMatrix[rowIdx][colIdx] / settings.rayInPixel);
        }
     
    }   
}

void Render::rendering(Render& render, const Scene3d& parsedScene, const std::string& filename, const MultithreadingMode& mMode) {
    mthreadMode = mMode;
    this->scene = parsedScene;
    int imageHeight = render.settings.imageHeight;
    int imageWidth = render.settings.imageWidth;
    int bucketSize = scene.getSettings().getBucketSize();
    scene.getAllTriangles();
    std::vector<std::thread> threads;

    std::vector<std::vector<ColorRGB>> pixelMatrix(imageHeight, std::vector<ColorRGB>(imageWidth));
    if (mMode == MultithreadingMode::Release) {  
        Bucket bucket(0, imageHeight,0, imageWidth);
        renderRegion(bucket, pixelMatrix);
    }
    else if (mMode == MultithreadingMode::RegionRendering) {
        RegionGenerator regionRender;
        regionRender.generateCoordinates(imageHeight, imageWidth, settings.cpuThreadsCount);
        std::vector<Bucket> regions = regionRender.getRegions();
        for (size_t i = 0; i < settings.cpuThreadsCount; ++i) {
            threads.emplace_back(std::thread(&Render::renderRegion, this, std::ref(regions[i]), std::ref(pixelMatrix)));
        }
        for (auto& thread : threads) {
            thread.join();
        }
    }
    else if (mMode == MultithreadingMode::BucketRendering || mMode == MultithreadingMode::AABBox || mMode == MultithreadingMode::KDTree) {
        if (mMode == MultithreadingMode::AABBox)  {
            scene.loadAABB();
            scene.isLoadedAABB = true;    
        }
        if (mMode == MultithreadingMode::KDTree ) {
            scene.loadAABB();
            scene.isLoadedAABB = true;
            kdtree = KdTree(settings, scene.getAABB(), scene.allTriangles);
            this->accTree = kdtree.getAccTree(); 
        }
        BucketGenerator bucketGenerator;
        bucketGenerator.BucketRendering(render, imageHeight, imageWidth, settings.bucketSize, settings.cpuThreadsCount , pixelMatrix);
    }
    else {
        assert("Invalid Multithreading mode");
    }
    this->pixelMatrix = pixelMatrix;
}