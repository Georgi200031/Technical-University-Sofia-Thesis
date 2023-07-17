#pragma once
#include <limits>
#include <utility> 
#include <iostream>
class AABB {
public:
	Vector3d boxMin;
	Vector3d boxMax;
	//Empty constructor
	AABB() : boxMin(Vector3d(maxFloatValue , maxFloatValue, maxFloatValue)), boxMax(Vector3d(minFloatValue, minFloatValue, minFloatValue)) {};
	//Constructor with parameters
	AABB( Vector3d& boxMin, Vector3d& boxMax) : boxMin(boxMin),boxMax(boxMax) {}

	//std::pair<AABB, AABB> split(const float& AASplitAxisIdx);
	//for each box having boxMin and boxMax coords according given object
	
	/*
		Split Function that get Axis Aligned Bounding Box and devide to two halves axis box
	*/	
	inline std::pair<AABB, AABB> split(const int& AASplitAxisIdx) {
		float mid = (boxMax.sideAxis(AASplitAxisIdx) - boxMin.sideAxis(AASplitAxisIdx)) / 2.0f;

		float splitPlaneCoordinate = boxMin.sideAxis(AASplitAxisIdx) + mid;


		AABB leftAABB(boxMin, boxMax);
		AABB rightAABB(boxMin, boxMax);

		leftAABB.boxMax.sideAxis(AASplitAxisIdx) = splitPlaneCoordinate;
		rightAABB.boxMin.sideAxis(AASplitAxisIdx) = splitPlaneCoordinate;

		return std::make_pair(leftAABB, rightAABB);
	}

	/*
		This function intersect two axis aligned Boundign boxes (if have intersect return true) else false for non intersect
	*/
	bool intersect(AABB& nodeAABB) {	
		for (int axis = 0; axis < 3; axis++) {
			if (boxMin.sideAxis(axis) > nodeAABB.boxMax.sideAxis(axis) + EPSILON || boxMax.sideAxis(axis) < nodeAABB.boxMin.sideAxis(axis)-EPSILON) {
				return false;
			}
		}
		return true;
	}

	//here intersect function is for intersect Ray with axis box
	bool intersectRay(Ray& ray,float& nearestT) {
		nearestT = std::numeric_limits<float>::max();
		float tNear = std::numeric_limits<float>::min();
		float tFar = std::numeric_limits<float>::max();
		for (int axis = 0; axis < 3; axis++) {
			float currMin = (boxMin.sideAxis(axis) - ray.origin.sideAxis(axis)) / ray.direction.sideAxis(axis);
			float currMax = (boxMax.sideAxis(axis) - ray.origin.sideAxis(axis)) / ray.direction.sideAxis(axis);
			
			if (currMin > currMax) {
				std::swap(currMin, currMax);
			}

			tNear = std::max(tNear, currMin);
			tFar = std::min(tFar, currMax);

			if (tNear > tFar) {
				return false;
			}
		}
		
		if (tNear < tFar && tNear < nearestT) {
			nearestT = tNear;
			return true;
		}
		return false;
	}
	
	std::vector<Triangle> triangles;
};