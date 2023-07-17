#pragma once
#include "Triangle.h"

Triangle::Triangle(const Vector3d& v0, const Vector3d& v1, const Vector3d& v2) {
    verts[0] = v0;
    verts[1] = v1;
    verts[2] = v2;
}

Vector3d Triangle::vertex(const int& index) const {
    assert(index >= 0 && index < 3);
    return verts[index];
}

Vector3d Triangle::edgeVector(const int& index) const {
    assert(index >= 0 && index < 3);
    if (index == 0) {
        return verts[1] - verts[0];
    }
    else if (index == 1) {
        return verts[2] - verts[1];
    }
    return verts[0] - verts[2];
}

bool Triangle::compare(const Vector3d& exampleVector) const {
    if(exampleVector == verts[0] || exampleVector == verts[1] || exampleVector == verts[2]){
        return true;
    }
    return false;
}

int Triangle::intersectRay(Ray& ray, const int& triangleIndx, intersectionData& data,float& closestIntersectionDistance,int& closestTriangleIndex) {
    if ((normalVertex().dot(ray.direction)) != EPSILON) {
        float rProj = ray.direction.dot(normalVertex());

        // calculate distance from ray.origin to plane
        float rpDist = (vertex(0) - ray.origin).dot(normalVertex());

        float t = rpDist / rProj;

        Vector3d planeRayIntersect = ray.origin + ray.direction * t;

        // check planeIntersect is near the triangle
        Vector3d V0P = Vector3d(planeRayIntersect - vertex(0));
        Vector3d V1P = Vector3d(planeRayIntersect - vertex(1));
        Vector3d V2P = Vector3d(planeRayIntersect - vertex(2));


        if (t >= -EPSILON &&
            normalVertex().dot(edgeVector(0).cross(V0P)) >= -EPSILON &&
            normalVertex().dot(edgeVector(1).cross(V1P)) >= -EPSILON &&
            normalVertex().dot(edgeVector(2).cross(V2P)) >= -EPSILON) {

            float intersectionDistance = t;

            
            if (intersectionDistance <= closestIntersectionDistance && intersectionDistance <= ray.minT) {
                if (ray.type == RayType::camera && material->backFaceCulling == true && ray.direction.dot(normalVertex()) > 0) {
                    
                }
                else {
                    Vector3d V0V1 = Vector3d(vertex(1) - vertex(0));
                    Vector3d V0V2 = Vector3d(vertex(2) - vertex(0));
                    float u = (V0P.cross(V0V2)).length() / (V0V1.cross(V0V2)).length();
                    float v = (V0V1.cross(V0P)).length() / (V0V1.cross(V0V2)).length();
                    float w = 1 - u - v;
                    data.baryCords.u = u * 255;
                    data.baryCords.v = v * 255;
                    data.hitPointNormal = v1Normal * u + v2Normal * v + v0Normal * w;
                    data.hitPoint = planeRayIntersect;
                    data.triangleIntersectNormal = normalVertex();

                    data.material = material;

                    closestIntersectionDistance = intersectionDistance;
                    data.distance = intersectionDistance;

                    closestTriangleIndex = triangleIndx;
                    data.intesectedTriInx = closestTriangleIndex;

                    ray.minT = intersectionDistance;
                }
            }
        }
    }
    return closestIntersectionDistance;
}