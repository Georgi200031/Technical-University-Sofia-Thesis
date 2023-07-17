#pragma once
#include <iostream>
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/document.h"
#include "ColorRGB.h"
#include "Render.h"
#include "Constants.h"
#include <vector>
#include <thread>
#include <limits>
#include <fstream>
class SceneParser {

public:
    /* Constructor set scene */
    SceneParser(std::string sceneFileName) : sceneFileName {sceneFileName} {}

    //Parse scene elements
    void parseSettings(Scene3d& scene, const rapidjson::Document& doc);
    void parseCamera(Scene3d& scene, const rapidjson::Document& doc);
    void parseLights(Scene3d& scene, const rapidjson::Document& doc);
    void parseObjects(Scene3d& scene, const rapidjson::Document& doc);
    void parseMaterials(Scene3d& scene, const rapidjson::Document& doc);

    // load scene file 
    void loadScene3d(Scene3d& scene);

private:
    std::string sceneFileName;
    rapidjson::Document getJsonDoc(const std::string& sceneFileName) noexcept;
    int vertexSize = 0;

    //loadVector function give from rapidjson value ConstArray and convert to arr
    Vector3d loadVector(const rapidjson::Value::ConstArray& arr);
    //loadMatrix function give from rapidjson value ConstArray  and convert to Matrix
    Matrix loadMatrix(const rapidjson::Value::ConstArray& matrix);
    //loadVertices function five from rapidjson value ConstArray and convert to vector<vertices>
    std::vector<Vector3d> loadVertices(const rapidjson::Value::ConstArray& vertices);
    //loadIndices function five from rapidjson value ConstArray and convert to vector<indices>
    std::vector<int> loadIndices(const rapidjson::Value::ConstArray& indices);
};