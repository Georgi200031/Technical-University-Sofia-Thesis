#pragma once
#include "Scene3d.h"
#include <iostream>

Scene3d::Scene3d() { }//Empty constructor

/* SETTERS */
void Scene3d::addSettings(const Settings& settings) {
        this->settings = settings;
    }
void Scene3d::addCamera(const Camera& camera) {
        this->camera = camera;
}
void Scene3d::addObjects(const MeshTriangles& object) {
        this->geometryObjects.emplace_back(object);
}
void Scene3d::addLights(const Lights3d& light) {
    this->light.emplace_back(light);
}
void Scene3d::addMaterials(const Material& materials) {
    this->materials.emplace_back(materials);
}


/*SETTERS*/
Settings& Scene3d::getSettings() {
    return settings;
}

Camera& Scene3d::getCamera() {
    return camera;
}

std::vector<Lights3d>& Scene3d::getLights() {
    return light;
}

const Material& Scene3d::getMaterial(const int& index) {
    return materials[index];
}

const MeshTriangles& Scene3d::getObject(const int& index) {
    return geometryObjects[index];
}
AABB& Scene3d::getAABB() {
    return boundingBox;
}

void Scene3d::getAllTriangles() {
    for (int object = 0; object < static_cast<int>(this->geometryObjects.size()); object++) {
        for (int triangleIndx = 0; triangleIndx < this->geometryObjects[object].getTrianglesArr().size(); triangleIndx++) {
            Triangle triangle = geometryObjects[object].getTriangles(triangleIndx);
            triangle.material = &geometryObjects[object].getMaterial();
            allTriangles.emplace_back(triangle);
        }
    }
}
void Scene3d::loadAABB() {
    int objects = static_cast<int>(this->geometryObjects.size());
    AABB sceneBox;
    for (int object = 0; object < objects; object++) {

        for (int triangleIndx = 0; triangleIndx < this->geometryObjects[object].getTrianglesArr().size(); triangleIndx++) {
            Triangle triangle = geometryObjects[object].getTriangles(triangleIndx);
           
            for (int i = 0; i < 3; i++) {
                sceneBox.boxMin = sceneBox.boxMin.min(triangle.vertex(i));
                sceneBox.boxMax = sceneBox.boxMax.max(triangle.vertex(i));
            }
        }
    }
    this->boundingBox=sceneBox;
}

int Scene3d::intersect(Ray& ray, intersectionData& data,const float& maxT) {
    int closestTriangleIndex = invalidIndexTriangle;
    float closestIntersectionDistance = maxT;
    float tNear = FLT_MAX;
    if (this->isLoadedAABB && ray.type == RayType::camera) {
        if (!this->boundingBox.intersectRay(ray, tNear)) return invalidIndexTriangle;
    }
    int triangleIndx = 0;
    for (Triangle triangle : allTriangles) {
        triangleIndx++;
        triangle.intersectRay(ray, triangleIndx, data, closestIntersectionDistance, closestTriangleIndex);
    }
    return closestTriangleIndex;
}
