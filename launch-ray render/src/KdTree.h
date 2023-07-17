#pragma once
#include <vector>
#include "AccTreeNode.h"
#include "AABB.h"
#include "renderSettings.h"

class KdTree {
public:
	KdTree() {}
	KdTree(renderSettings& renderSettigns, AABB& aabb, std::vector<Triangle>& allTriangles);

	void buildAccTree(const int& parentIdx, const int& depth, const std::vector<Triangle>& triangles);
	//if ray is not shadow  maxT => FLT_MAX if shadow maxT = rad (when ray is created ray.maxT and ray.minT = FLT_MAX)
	intersectionData KdTreeAlgorithm(Ray& ray, float& maxT);

	std::vector<AccTreeNode> getAccTree();

private:
	renderSettings renderSettigns;
	std::vector<AccTreeNode> accTree;
	std::vector<Triangle>triangle;
	AABB aabb;
};