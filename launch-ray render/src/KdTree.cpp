#include "ColorRGB.h"
#include "Scene3d.h"
#include <stack>
#include <vector>
#include <iostream>
#include <thread>
#include <limits>
#include <fstream>
#include "Vector3d.h"
#include "AccTreeNode.h"
#include "KdTree.h"

void KdTree::buildAccTree(const int& parentIdx, const int& depth, const std::vector<Triangle>& triangles) {

	if (depth >= renderSettigns.accTreeDepth || triangles.size() <= renderSettigns.maxBoxTrianglesCount) {
		accTree[parentIdx].triangles = triangles;
		return;
	}
	//split algorithm
	int AASplitAxisIdx = depth % axisCount;
	std::pair<AABB, AABB> result = accTree[parentIdx].aabb.split(AASplitAxisIdx);
	AABB& child0AABB = result.first;/*leftAABB */
	AABB& child1AABB = result.second;/*rightAABB*/

	for (const Triangle& triangle : triangles) {
		AABB triangleAABB;

		for (int axis = 0; axis < 3; axis++) {
			triangleAABB.boxMin = triangleAABB.boxMin.min(triangle.vertex(axis));
			triangleAABB.boxMax = triangleAABB.boxMax.max(triangle.vertex(axis));
		}

		if (triangleAABB.intersect(child0AABB)) {
			child0AABB.triangles.push_back(triangle);

		}
		if (triangleAABB.intersect(child1AABB)) {
			child1AABB.triangles.push_back(triangle);

		}

	}

	if (child0AABB.triangles.size() > 0) {
		accTree.emplace_back(AccTreeNode(child0AABB, -1, -1, std::vector<Triangle>()));
		int child0Idx = static_cast<int>(accTree.size()) - 1;
		accTree[parentIdx].children[0] = child0Idx;
		buildAccTree(child0Idx, depth + 1, child0AABB.triangles);
	}

	if (child1AABB.triangles.size() > 0) {
		accTree.emplace_back(AccTreeNode(child1AABB, -1, -1, std::vector<Triangle>()));
		int child1Idx = static_cast<int>(accTree.size()) - 1;
		accTree[parentIdx].children[1] = child1Idx;
		buildAccTree(child1Idx, depth + 1, child1AABB.triangles);
	}

}

KdTree::KdTree(renderSettings& renderSettigns, AABB& aabb, std::vector<Triangle>& allTriangles) : aabb(aabb), triangle(allTriangles) {
	this->renderSettigns = renderSettigns;
	accTree.push_back(AccTreeNode(aabb, -1, -1, std::vector<Triangle>()));
	int parentIndx = 0;
	int depth = 0;
	buildAccTree(parentIndx, depth, allTriangles);
}

intersectionData KdTree::KdTreeAlgorithm(Ray& ray, float& maxT) {
	intersectionData data;
	std::stack<int> nodeIndicesToCheck;
	nodeIndicesToCheck.push(0);
	data.intesectedTriInx = invalidIndexTriangle;
	float nearestBox = maxT;
	while (nodeIndicesToCheck.size() > 0) {
		int currentNodeIdxToCheck = nodeIndicesToCheck.top();

		nodeIndicesToCheck.pop();

		AccTreeNode& currentNode = accTree[currentNodeIdxToCheck];

		if (currentNode.aabb.intersectRay(ray, nearestBox)) {
			if (currentNode.triangles.size() > 0) {

				if (currentNode.intersect(ray, maxT, data, currentNode.triangles) != -1) {
					maxT = data.distance;
				}
			}
			else {
				if (currentNode.children[0] != -1) {
					nodeIndicesToCheck.push(currentNode.children[0]);
				}
				if (currentNode.children[1] != -1) {
					nodeIndicesToCheck.push(currentNode.children[1]);
				}
			}
		}
	}
	return data;
}

std::vector<AccTreeNode> KdTree::getAccTree() {
	return accTree;
}