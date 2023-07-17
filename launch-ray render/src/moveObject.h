#pragma once
#include "SceneParser.h"
#include <chrono>
#include <iostream>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/ostreamwrapper.h"
#include "rapidjson/writer.h"

class moveObject {
public:
    moveObject(const std::string inputFileScene,const int& objectIdx) :inputFileScene(inputFileScene), objectIdx(objectIdx){
    }
    void moveByX(const float& step) {
        std::ifstream inputFile(inputFileScene);
        assert(inputFile.is_open());

        rapidjson::IStreamWrapper inStream(inputFile);
        rapidjson::Document doc;
        doc.ParseStream(inStream);

        if (doc.HasParseError()) {
            std::cout << "Parse Error: " << doc.GetParseError() << "\n";
            std::cout << "Error Offset: " << doc.GetErrorOffset() << "\n";
            assert(false);
        }
        assert(doc.IsObject());

        rapidjson::Value& objectVal = doc.FindMember(OBJECTS)->value;
        //std::cout << objectVal.Size();
        if (objectVal.IsArray()) {
            for (rapidjson::SizeType objectIndx = 0; objectIndx < objectVal.Size(); objectIndx++) {
                rapidjson::Value& verticesVal = objectVal[objectIndx].FindMember(VERTICES)->value;
                if (verticesVal.IsArray()) {
                    assert(verticesVal.Size() % 3 == 0);

                    for (rapidjson::SizeType j = 0; j < verticesVal.Size(); j += 3) {
                        float x = verticesVal[j].GetFloat();


                        // Perform operations on the vertex coordinates
                        if (objectIndx == objectIdx) {
                            x = x - step;

                        }

                        // Update the vertex coordinates
                        verticesVal[j].SetFloat(x);
                    }
                }
            }
        }

        inputFile.close();

        // Write the modified JSON document back to the original file
        std::ofstream outputFile(inputFileScene);
        assert(outputFile.is_open());

        rapidjson::OStreamWrapper outStream(outputFile);
        rapidjson::Writer<rapidjson::OStreamWrapper> writer(outStream);
        doc.Accept(writer);

        outputFile.close();
    }

    void moveByZ(const float& step) {
        std::ifstream inputFile(inputFileScene);
        assert(inputFile.is_open());

        rapidjson::IStreamWrapper inStream(inputFile);
        rapidjson::Document doc;
        doc.ParseStream(inStream);

        if (doc.HasParseError()) {
            std::cout << "Parse Error: " << doc.GetParseError() << "\n";
            std::cout << "Error Offset: " << doc.GetErrorOffset() << "\n";
            assert(false);
        }
        assert(doc.IsObject());

        rapidjson::Value& objectVal = doc.FindMember(OBJECTS)->value;
        //std::cout << objectVal.Size();
        if (objectVal.IsArray()) {
            for (rapidjson::SizeType objectIndx = 0; objectIndx < objectVal.Size(); objectIndx++) {
                rapidjson::Value& verticesVal = objectVal[objectIndx].FindMember(VERTICES)->value;
                if (verticesVal.IsArray()) {
                    assert(verticesVal.Size() % 3 == 0);

                    for (rapidjson::SizeType j = 0; j < verticesVal.Size(); j += 3) {

                        float z = verticesVal[j + 2].GetFloat();

                        // Perform operations on the vertex coordinates
                        if (objectIndx == objectIdx) {
                            z = z + step;

                        }

                        // Update the vertex coordinates

                        verticesVal[j + 2].SetFloat(z);
                    }
                }
            }
        }

        inputFile.close();

        // Write the modified JSON document back to the original file
        std::ofstream outputFile(inputFileScene);
        assert(outputFile.is_open());

        rapidjson::OStreamWrapper outStream(outputFile);
        rapidjson::Writer<rapidjson::OStreamWrapper> writer(outStream);
        doc.Accept(writer);

        outputFile.close();
    }

    void moveByY(const float& step) {
        std::ifstream inputFile(inputFileScene);
        assert(inputFile.is_open());

        rapidjson::IStreamWrapper inStream(inputFile);
        rapidjson::Document doc;
        doc.ParseStream(inStream);

        if (doc.HasParseError()) {
            std::cout << "Parse Error: " << doc.GetParseError() << "\n";
            std::cout << "Error Offset: " << doc.GetErrorOffset() << "\n";
            assert(false);
        }
        assert(doc.IsObject());

        rapidjson::Value& objectVal = doc.FindMember(OBJECTS)->value;
        //std::cout << objectVal.Size();
        if (objectVal.IsArray()) {
            for (rapidjson::SizeType objectIndx = 0; objectIndx < objectVal.Size(); objectIndx++) {
                rapidjson::Value& verticesVal = objectVal[objectIndx].FindMember(VERTICES)->value;
                if (verticesVal.IsArray()) {
                    assert(verticesVal.Size() % 3 == 0);

                    for (rapidjson::SizeType j = 0; j < verticesVal.Size(); j += 3) {
                        float y = verticesVal[j + 1].GetFloat();


                        // Perform operations on the vertex coordinates
                        if (objectIndx == objectIdx) {
                            y = y + step;

                        }

                        // Update the vertex coordinates
                        verticesVal[j + 1].SetDouble(y);
                    }
                }
            }
        }

        inputFile.close();

        // Write the modified JSON document back to the original file
        std::ofstream outputFile(inputFileScene);
        assert(outputFile.is_open());

        rapidjson::OStreamWrapper outStream(outputFile);
        rapidjson::Writer<rapidjson::OStreamWrapper> writer(outStream);
        doc.Accept(writer);

        outputFile.close();
    }

   

private:
    int objectIdx;
    std::string inputFileScene;
};