#pragma once
#include "Camera.h"
#include "IntersectionData.h"

enum class RayType {
    invalid,
    camera,//Ray shot from the camera
    shadow,//When shading deffuse material
    reflection,//after reflective material is hit
    refraction//after refractive material is hit
};
struct Ray {
    Ray() : origin(Vector3d(0, 0, 0)), direction(Vector3d(0, 0, 0)),depth(0), type(RayType::invalid) { }
    Ray(Vector3d origin, Vector3d direction,float depth,RayType type) :origin(origin),direction(direction),depth(depth),type(type) { }

    Vector3d origin;
    Vector3d direction;
    
    float minT = FLT_MAX;
    float maxT = FLT_MAX;
    float depth;
    RayType type;
};
/* function generate camera ray */
Ray generateCameraRay(const int& rowIdx, const int& colIdx, const int& imageWidth, const int& imageHeight,const Camera& camera,const float& fovAngle);
/* function that create Reflected Ray by intersection data and origin ray then return reflected ray */
Ray computeReflectedRay(const Ray& ray, const Vector3d& hitPoint, const Vector3d& normal,const RayType& rayType);
/* function that create Refractive Ray by intersection data and origin ray then return refractived ray */
Ray computeRefractiveRay(const Ray& ray, const Vector3d& hitPoint, const Vector3d& normal,const float& sinBeta,const float& cosAlpha,float& eta);