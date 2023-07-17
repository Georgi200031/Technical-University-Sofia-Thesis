#pragma once
#include <string>
#include "Vector3d.h"

/// <summary>
/// MaterialType is named values of the material witch ray is hit
/// Material sturcture store information about material witch type is (MaterialType), is have or not smoothShading and Vector3d albedo 
/// </summary>

enum MaterialType {
    diffuse,
    smoothShadingdiffuse,
    constant,
    background,
    reflective,
    refractive,
};
struct Material {
public:
    /* Empty constructor */
    Material() : type(diffuse), albedo(1, 1, 1), ior(0.0f), smoothShading(), backFaceCulling(false) {}

    /* Constructor to set type, albedo, and smoothShading */
    Material(const MaterialType& type, const Vector3d& albedo, bool smoothShading) :
        type(type), albedo(albedo), ior(0.0f), smoothShading(smoothShading), backFaceCulling(false) {}

    /* Constructor for refractive material */
    Material(const MaterialType& type, const Vector3d& albedo, float ior, bool smoothShading) :
        type(type), albedo(albedo), ior(ior), smoothShading(smoothShading), backFaceCulling(false) {}

    /* Constructor for refractive material */
    Material(const MaterialType& type, const Vector3d& albedo, bool smoothShading, bool backFaceCulling) :
        type(type), albedo(albedo), ior(0.0f), smoothShading(smoothShading), backFaceCulling(backFaceCulling) {}

    MaterialType type;
    Vector3d albedo;
    float ior;
    bool smoothShading;
    bool backFaceCulling;
};

/* function convert taken information about material when parsed scene and return Material type */
MaterialType convertToMaterialType(const std::string& str);