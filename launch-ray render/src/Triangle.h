#pragma once
#include "Vector3d.h"
#include <assert.h>
#include "Material.h"
#include "IntersectionData.h"
#include "Ray.h"

static const int vertsInTriangle = 3;

class Triangle {
public:
    /* Construcotor of triangle set three vertices */
    Triangle(const Vector3d& v0, const Vector3d& v1, const Vector3d& v2);

    //Get vertex of the triangle between 0 and 2 vertex
    Vector3d vertex(const int& index) const;

    const Material* material;

    //function get normal Vertex of triangle
    Vector3d normalVertex() {
        normal = (verts[1] - verts[0]).cross(verts[2] - verts[0]);
        normal.normalize();
        return normal;
    };
    
    //this function compare exampleVector with Triangle if any triangle vertex is equal to exampleVector return true; 
    bool compare(const Vector3d& exampleVector) const;

    //here define triangle normal vertex for each vertex
    Vector3d v0Normal,v1Normal,v2Normal;

    //function get edge vertex
    Vector3d edgeVector(const int& index) const;

    int intersectRay(Ray& ray, const int& triangleIndx, intersectionData& data, float& closestIntersectionDistance, int& closestTriangleIndex);

private:
    Vector3d verts[vertsInTriangle];
    Vector3d normal;
};