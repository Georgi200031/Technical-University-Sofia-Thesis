#pragma once
#include <mutex>
#include <vector>
#include "ColorRGB.h"
#include <thread>

class Render;

struct Bucket {
public:
	//Constructor with parameters
	Bucket(const int& startX, const int& endX, const int& startY, const int& endY) : startX(startX), endX(endX), startY(startY), endY(endY) { }
	int startX;
	int startY;
	int endX;
	int endY;
};

// class BucketGenerator have one function that generate buckets after set bucket size and store it in vector of Buckets
class BucketGenerator {
public:
	//Empty constructor
	BucketGenerator() {}
	/*
		function create array with buckets and calculte coordinates of each bucket
		 each bucket is with size given from scene.Bucket array is created horizontally
	*/
	void createBucketArray(Render& render, const int& imageHeight, const int& imageWidth, const int& bucketSize, std::vector<std::vector<ColorRGB>>& pixelMatrix);
	void BucketRendering(Render& render, const int& imageHeight, const int& imageWidth, const int& bucketSize, int cpuThreadsCount, std::vector<std::vector<ColorRGB>>& pixelMatrix);
private:
	const size_t numberOfThreads = std::thread::hardware_concurrency();
	std::vector<std::thread> threads; 
	void BucketArray(const int& imageHeight, const int& imageWidth, const int& bucketSize);
	std::vector<Bucket> buckets;
};
