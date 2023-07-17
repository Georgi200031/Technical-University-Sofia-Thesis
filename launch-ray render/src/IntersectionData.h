#pragma once
#include "Material.h"
#include "BaryCoords.h"
/// <summary> 
///  structure intersectionData store information about hitted object.
/// </summary>
struct intersectionData {
    intersectionData() {}
    Vector3d hitPoint;
    Vector3d hitPointNormal;
    Vector3d triangleIntersectNormal;
    BaryCoords baryCords = BaryCoords(0,0);
    int intesectedTriInx = invalidIndexTriangle;
    const Material* material = nullptr;
    float distance = -std::numeric_limits<float>::infinity();
  
};

