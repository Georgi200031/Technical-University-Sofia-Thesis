#pragma once
#include <vector>
#include "AABB.h"
#include "Triangle.h"
#include "intersectionData.h"
#include "Ray.h"
/// <summary>
/// Node for the acceleration tree structure
/// holding box for the sub space the node represents
/// </summary>
struct AccTreeNode {
	AccTreeNode(const AABB& aabb, int leftNodeIdx, int rightNodeIdx, const std::vector<Triangle>& triangles)
	{
		this->aabb = aabb;
		this->triangles = triangles;
		children[0] = leftNodeIdx;
		children[1] = rightNodeIdx;
	}
    
    int intersect(Ray& ray, float& maxT, intersectionData& data, std::vector<Triangle> triangles) {
        int closestTriangleIndex = invalidIndexTriangle;
        float closestIntersectionDistance = maxT;
        int triangleIndx = invalidIndexTriangle;
        for (Triangle& triangle : triangles) {
            triangleIndx++;	
			triangle.intersectRay(ray, triangleIndx, data, closestIntersectionDistance, closestTriangleIndex);
        }
        return closestTriangleIndex;
    }
	std::vector<Triangle> triangles;//in case  if have leaf node store triangles of it.
	AABB aabb;//Axis aligned bounding box for node 
	int children[2];//left and righr indices for the node's children
	int parent = invalidParent;//Index for parent node
};
