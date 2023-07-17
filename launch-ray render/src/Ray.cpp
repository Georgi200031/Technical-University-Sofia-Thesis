#pragma once
#include "Ray.h" 
#include <cmath>
Ray generateCameraRay(const int& rowIdx,const int& colIdx,const int& imageWidth, const int& imageHeight, const Camera& camera,const float& fovAngle) {
    // Find random offset within pixel
    float offsetX = static_cast<float>(std::rand()) / RAND_MAX;
    float offsetY = static_cast<float>(std::rand()) / RAND_MAX;

    // Find center of the offset pixel
      float x = (static_cast<float>(rowIdx) + offsetX) + 0.5f;
      float y = (static_cast<float>(colIdx) + offsetY) + 0.5f;
    //float x = rowIdx + 0.5f;
   // float y = colIdx + 0.5f;

    // Convert raster to NDC
    x /= static_cast<float>(imageHeight * (static_cast<float>(imageWidth) / static_cast<float>(imageHeight)));
    y /= static_cast<float>(imageHeight);

    // Convert NDC to screen
    x = (2.0f * x) - 1.0f;
    y = 1.0f - (2.0f * y);

    // Apply aspect ratio
    x *= static_cast<float>(imageWidth) / static_cast<float>(imageHeight);
    if (fovAngle <= 360 && fovAngle > 0) {
        const float radians = fovAngle * (PI / 180.0f);
        float tanHalfFOV = tan(radians / 2);
        x = x * tanHalfFOV;
        y = y * tanHalfFOV;
    }

    Vector3d direction = Vector3d(x, y, -1.0);
    direction = camera.getRotationMatrix() * direction;
    direction.normalize();
    RayType type = RayType::camera;

    return Ray(camera.getPosition(), direction, 0, type);
}

Ray computeReflectedRay(const Ray& ray, const Vector3d& hitPoint,const Vector3d& normal, const RayType& rayType) {
    if (rayType == RayType::refraction) {
        Vector3d reflectedDir = ray.direction - normal * 2 * ray.direction.dot(normal);
        return Ray(hitPoint + normal * REFLECTION_RAY_BIAS, reflectedDir, ray.depth + 1, RayType::refraction);
    }
    Vector3d incomingRay = ray.direction;
    Vector3d reflectedDir = incomingRay - normal * 2 * incomingRay.dot(normal);
    return Ray(hitPoint + normal * REFLECTION_RAY_BIAS, reflectedDir, ray.depth + 1, rayType);
}
Ray computeRefractiveRay(const Ray& ray, const Vector3d& hitPoint, const Vector3d& normal,const float& sinBeta,const float& cosAlpha,float& eta) {
    const float cos2ThetaT = 1 - eta * eta * (1 - cosAlpha * cosAlpha);
    const float cosThetaT = sqrtf(cos2ThetaT);
    Vector3d refractedRayDirection = ray.direction * eta + normal * (eta * cosAlpha - cosThetaT);
    refractedRayDirection.normalize();
    return Ray (hitPoint - normal * REFRACTION_RAY_BIAS, refractedRayDirection, ray.depth + 1, RayType::refraction);
}






   

