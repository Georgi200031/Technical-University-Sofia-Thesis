#pragma once
#include "SceneParser.h"
rapidjson::Document SceneParser::getJsonDoc(const std::string& filename) noexcept {
    std::ifstream input(filename);
    assert(input.is_open());

    rapidjson::IStreamWrapper inStream(input);
    rapidjson::Document doc;
    doc.ParseStream(inStream);

    if (doc.HasParseError()) {
        std::cout << "Parse Error: " << doc.GetParseError() << "\n";
        std::cout << "Error Offset: " << doc.GetErrorOffset() << "\n";
        assert(false);
    }
    assert(doc.IsObject());
    return doc;
}

void SceneParser::parseSettings(Scene3d& scene, const rapidjson::Document& doc) {
    const rapidjson::Value& settingsVal = doc.FindMember(SETTINGS)->value;
    const rapidjson::Value& imgSettingsVal = settingsVal.FindMember(IMGSETTINGS)->value;
    Settings settings;
    if (!settingsVal.IsNull() && settingsVal.IsObject()) {
        const rapidjson::Value& imgWidthVal = imgSettingsVal.FindMember(WIDTH)->value;
        const rapidjson::Value& imgHeightVal = imgSettingsVal.FindMember(HEIGHT)->value;
        const rapidjson::Value& imgBucketVal = imgSettingsVal.FindMember(BUCKETSIZE)->value;

        assert(!imgWidthVal.IsNull() && imgWidthVal.IsInt() && !imgHeightVal.IsNull() && imgHeightVal.IsInt());
        settings.setImageHeight(imgHeightVal.GetInt());
        settings.setImageWidth(imgWidthVal.GetInt());
        settings.setBucketSize(imgBucketVal.GetInt());
    }

    const rapidjson::Value& bgColor = settingsVal.FindMember(BGCOLOR)->value;
    assert(!bgColor.IsNull() && bgColor.IsArray());
    
    settings.setBgColor(loadVector(bgColor.GetArray()));

    const rapidjson::Value& giVAL = settingsVal.FindMember(GI_ON)->value;
    assert(!giVAL.IsNull() && giVAL.IsBool());
    settings.setGiOn(giVAL.GetBool());

    const rapidjson::Value& reflectanseVal = settingsVal.FindMember(REFLECTIONS_ON)->value;
    assert(!reflectanseVal.IsNull() && reflectanseVal.IsBool());
    settings.setReflectionsOn(reflectanseVal.GetBool());


    const rapidjson::Value& refractenseVal = settingsVal.FindMember(REFRACTIONS_ON)->value;
    assert(!refractenseVal.IsNull() && refractenseVal.IsBool());
    settings.setRefractionsOn(refractenseVal.GetBool());
    

    scene.addSettings(settings);
}

void SceneParser::parseCamera (Scene3d& scene, const rapidjson::Document& doc) {
    const rapidjson::Value &cameraVal = doc.FindMember(CAMERA)->value;
    const rapidjson::Value &matrixVal = cameraVal.FindMember(MATRIX)->value;
    Camera camera;
    if (!cameraVal.IsNull() && cameraVal.IsObject()) {
        assert(!matrixVal.IsNull() && matrixVal.IsArray());
        camera.setRotationMatrix(loadMatrix(matrixVal.GetArray()));
    }
    const rapidjson::Value &positionVal = cameraVal.FindMember(POS)->value;
    if (!cameraVal.IsNull() && cameraVal.IsObject()) {
        assert(!positionVal.IsNull() && positionVal.IsArray());
        camera.setPosition(loadVector(positionVal.GetArray()));
    }
    scene.addCamera(camera);
}

void SceneParser::parseLights(Scene3d& scene, const rapidjson::Document& doc) {
    Lights3d light(Vector3d(0,0,0),0);
    const rapidjson::Value& lightValue = doc.FindMember(LIGHTS)->value;
    if(!lightValue.IsNull() && lightValue.IsArray()) {
        for(unsigned int i = 0;i < lightValue.Size();i++) {
            const rapidjson::Value& positionLights = lightValue[i].FindMember(POS)->value;
            assert(!positionLights.IsNull() && positionLights.IsArray());
            light.setPosition(loadVector(positionLights.GetArray()));

            const rapidjson::Value& intensityLights = lightValue[i].FindMember(LIGHTINTENSITY)->value;
            assert(!intensityLights.IsNull() && intensityLights.IsNumber());
            light.setIntensity(intensityLights.GetInt());
            scene.addLights(light);
        }
    }
}

void SceneParser::parseObjects(Scene3d& scene, const rapidjson::Document& doc) {
    const rapidjson::Value& objectVal = doc.FindMember(OBJECTS)->value;
    if (!objectVal.IsNull() && objectVal.IsArray()) {
        for (unsigned int i = 0; i < objectVal.Size(); i++) {
            MeshTriangles mesh;

            const rapidjson::Value& matIndexVal = objectVal[i].FindMember(MAT_INDEX)->value;
            assert(!matIndexVal.IsNull() && matIndexVal.IsNumber());
            
            int materialIndex = matIndexVal.GetInt();
            Material materialType = scene.getMaterial(materialIndex);
            mesh.setMaterial(materialType);

            const rapidjson::Value& verticesVal = objectVal[i].FindMember(VERTICES)->value;
            assert(!verticesVal.IsNull() && verticesVal.IsArray());

            mesh.setVertices(loadVertices(verticesVal.GetArray()));

            const rapidjson::Value& trianglesVal = objectVal[i].FindMember(TRIANGLES)->value;
            assert(!trianglesVal.IsNull() && trianglesVal.IsArray());
            std::vector<int> a;
            a = loadIndices(trianglesVal.GetArray());
            mesh.setTriangleVertIndices(a);
            
            mesh.loadTriangles();
            mesh.loadNormal();
            scene.addObjects(mesh);
        }
    }
}

void SceneParser::parseMaterials(Scene3d& scene, const rapidjson::Document& doc) {
    const rapidjson::Value& matVal = doc.FindMember(MATERIALS)->value;
    if (!matVal.IsNull() && matVal.IsArray()) {

      for (unsigned int i = 0; i < matVal.Size(); i++) {
        
        const rapidjson::Value& typeVal = matVal[i].FindMember(MAT_TYPE)->value;
        assert(!typeVal.IsNull() && typeVal.IsString());

        std::string materialString = typeVal.GetString();
        MaterialType materialType = convertToMaterialType(materialString);

        const rapidjson::Value& smoothVal = matVal[i].FindMember(MAT_SMOOTH)->value;
        assert(!smoothVal.IsNull() && smoothVal.IsBool());
        bool smooth = smoothVal.GetBool();

        if (materialType == MaterialType::diffuse || materialType == MaterialType::reflective) {
            Vector3d albedo;
            const rapidjson::Value& albedoVal = matVal[i].FindMember(MAT_ALBEDO)->value;
            assert(!albedoVal.IsNull() && albedoVal.IsArray());
            albedo = loadVector(albedoVal.GetArray());

            const rapidjson::Value& backfaceVal = matVal[i].FindMember("back_face_culling")->value;
            assert(!backfaceVal.IsNull() && backfaceVal.IsBool());
             bool backfaceCulling = backfaceVal.GetBool();
                
          
            scene.addMaterials(Material(materialType, albedo, smooth,backfaceCulling));
        }
        else if (materialType == MaterialType::refractive) {
            Vector3d albedo;
            const rapidjson::Value& iorVal = matVal[i].FindMember(MAT_IOR)->value;
            assert(!iorVal.IsNull() && iorVal.IsFloat());
            const float ior = iorVal.GetFloat();
            const rapidjson::Value& albedoVal = matVal[i].FindMember(MAT_ALBEDO)->value;
            assert(!albedoVal.IsNull() && albedoVal.IsArray());
            albedo = loadVector(albedoVal.GetArray());
            scene.addMaterials(Material(materialType,albedo, ior, smooth));
        }
        else if (materialType == MaterialType::constant) {
            Vector3d albedo;
            const rapidjson::Value& albedoVal = matVal[i].FindMember(MAT_ALBEDO)->value;
            assert(!albedoVal.IsNull() && albedoVal.IsArray());
            albedo = loadVector(albedoVal.GetArray());
            scene.addMaterials(Material(materialType, albedo, smooth));
        }
      }
    }
  }

void SceneParser::loadScene3d(Scene3d& scene) {
    rapidjson::Document doc = getJsonDoc(this->sceneFileName);
  
    parseSettings(scene, doc);
    parseCamera(scene,doc);
    parseMaterials(scene, doc);
    parseObjects(scene,doc);
    parseLights(scene,doc);
   
}


Vector3d SceneParser::loadVector(const rapidjson::Value::ConstArray& arr) {
    assert(arr.Size() == 3);
    Vector3d vec(arr[0].GetFloat(), arr[1].GetFloat(), arr[2].GetFloat());
    return vec;
}

Matrix SceneParser::loadMatrix(const rapidjson::Value::ConstArray& matrix) {
    assert(matrix.Size() == 9);
    Matrix mat= Matrix(matrix[0].GetFloat(), matrix[1].GetFloat(), matrix[2].GetFloat(),
                       matrix[3].GetFloat(), matrix[4].GetFloat(), matrix[5].GetFloat(),
                       matrix[6].GetFloat(), matrix[7].GetFloat(), matrix[8].GetFloat());
    return mat;
}

std::vector<Vector3d> SceneParser::loadVertices(const rapidjson::Value::ConstArray& vertices) {
   std::vector<Vector3d> vectors;
   assert(vertices.Size() % 3 == 0);
   for (unsigned int i = 0; i < vertices.Size() / 3; i++) {
        Vector3d vec = Vector3d(vertices[3 * i].GetFloat(),
                                vertices[3 * i + 1].GetFloat(),
                                vertices[3 * i + 2].GetFloat());
        vectors.emplace_back(vec);
   }
   vertexSize = vertexSize + vertices.Size();
   return vectors;
}

std::vector<int> SceneParser::loadIndices(const rapidjson::Value::ConstArray& trianglesVal) {
    
 std::vector<int> indices;
    assert(trianglesVal.Size() % 3 == 0);
    for (unsigned int j = 0; j < trianglesVal.Size(); j++) {
            indices.emplace_back(trianglesVal[j].GetInt());
    }
    return indices;
}