#pragma once
#include "Lights3d.h"
#include "Settings.h"
#include "MeshTriangles.h"
#include "Ray.h"
#include "Constants.h"
#include "AABB.h"
class Scene3d {
public:
    Scene3d();

    /* Setters */
    void addSettings(const Settings& settings);
    void addCamera(const Camera& camera);
    void addObjects(const MeshTriangles& object);
    void addLights(const Lights3d& light);
    void addMaterials(const Material& materials);

    /* Getters */
    Camera& getCamera();
    Settings& getSettings();
    std::vector<Lights3d>& getLights();
    const Material& getMaterial(const int& index);
    const MeshTriangles& getObject(const int& index);
    void getAllTriangles();
    AABB& getAABB();
    //loadAABB() is for find for each bounding box (boxMin,BoxMax according triangle coords)
    void loadAABB();
     //Find the closest intersection point if any.
     // - Returns intersected Triangle Index 
     // - If no intersection found, returns -1.0.
    int intersect(Ray& ray, intersectionData& data, const float& maxT);
    //bool operator for check if use AABB optimazing algorithm
    bool isLoadedAABB = false;
    std::vector<Triangle> allTriangles;
private:
    //Find the clestest intersection point if any according bounding box
    std::vector<MeshTriangles> geometryObjects;
    Camera camera;
    Settings settings;
    std::vector<Lights3d> light;
    std::vector<Material> materials;
    AABB boundingBox;
};