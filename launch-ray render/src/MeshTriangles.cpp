#pragma once
#include "MeshTriangles.h"
#include <iostream>

MeshTriangles::MeshTriangles() {};

/* SETTERS */

void MeshTriangles::setVertices(const std::vector<Vector3d>& vertices) {
    this->vertices = vertices;
}

void MeshTriangles::setTriangleVertIndices(std::vector<int>& triangleVertIndices) {
    this->triangleVertIndices = triangleVertIndices;
}

void MeshTriangles::setMaterial(Material& material) {
    this->material = material;
}

void MeshTriangles::setVertexNormal(Vector3d& vec) {
    vertexNormal.emplace_back(vec);
}

/* GETTERS */

Triangle& MeshTriangles::getTriangles(int& index) {
    return triangles[index];
}

std::vector<Triangle>& MeshTriangles::getTrianglesArr() {
    return triangles;
}

const Material& MeshTriangles::getMaterial() const{
    return material;
}

void MeshTriangles::loadNormal() { 
    //for each vertex calculate sum of triangle normal vectors which is contains
    for(Vector3d vertex : vertices) {
        Vector3d sumTriangleNormalVertex;
        for (Triangle triangle : triangles) {
            if(triangle.compare(vertex)) {
                sumTriangleNormalVertex = sumTriangleNormalVertex + triangle.normalVertex();
            }
        }
        sumTriangleNormalVertex.normalize();
        this->vertexNormal.emplace_back(sumTriangleNormalVertex); 
        
    }
    //Clear triangle and load Triangles because of add normal of vertex to triangles    
    triangles.clear();
    loadTriangles();
}

void MeshTriangles::loadTriangles() {
    for(int i = 0; i < triangleVertIndices.size() / 3 ; i++) {
        Triangle triangle {vertices[triangleVertIndices[3 * i]],
                           vertices[triangleVertIndices[3 * i + 1]],
                           vertices[triangleVertIndices[3 * i + 2]]};
        if (vertexNormal.size() != 0) {
            triangle.v0Normal = this->vertexNormal[triangleVertIndices[3 * i]];
            triangle.v1Normal = this->vertexNormal[triangleVertIndices[3 * i + 1]];
            triangle.v2Normal = this->vertexNormal[triangleVertIndices[3 * i + 2]];
        }
        
        this->triangles.emplace_back(triangle);
    }
}

