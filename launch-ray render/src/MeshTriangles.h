#pragma once
#include <vector>
#include "IntersectionData.h"
#include "Vector3d.h"
#include "Triangle.h"

class MeshTriangles {
public:
    /* Empty constructor */
    MeshTriangles();
    
    /* SETTERS */
    void setVertices(const std::vector<Vector3d>& vertex);
    void setTriangleVertIndices(std::vector<int>& triangleVertIndices);
    void setMaterial(Material& material);
    void setVertexNormal(Vector3d& vec);

    /* GETTERS */
    Triangle& getTriangles(int& index);
    std::vector<Triangle>& getTrianglesArr();
    const Material& getMaterial() const;
    
    /// <summary>
    /// loadNormal() function is calculate for each vertex of Trinalges sum of triangle normal vectors which is contains.
    /// and stored it in "vertexNormal" then we use loadTrianlges() to set vertexNormal in triangles (each triangle class have v0,v1 and v2 Normals witch store here)
    /// </summary>
    void loadNormal();
    void loadTriangles();
private:
    std::vector<Vector3d> vertices;
    std::vector<Triangle> triangles;
    std::vector<Vector3d> vertexNormal;
    Material material;
    std::vector<int> triangleVertIndices;
};