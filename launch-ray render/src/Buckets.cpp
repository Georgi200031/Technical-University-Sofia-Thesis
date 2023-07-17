#pragma once 
#include "Buckets.h"
#include "Render.h" 


void BucketGenerator::createBucketArray(Render& render,const int& imageHeight, const int& imageWidth, const int& bucketSize, std::vector<std::vector<ColorRGB>>& pixelMatrix) {
    std::mutex bucketMutex;
    while (true) {
        // Lock the bucket (wait until bucket can be locked)
        std::unique_lock<std::mutex> lock(bucketMutex);

        // Check if there are no more buckets left
        if (buckets.empty()) {

            // No more buckets, exit the thread
            return;
        }

        // Pop a bucket
        Bucket bucket = buckets.back();
        buckets.pop_back();

        // Unlock the bucket
        lock.unlock();

        // Invoke region rendering for the bucket
        render.renderRegion(bucket, pixelMatrix);
    }
}

void BucketGenerator::BucketRendering(Render& render, const int& imageHeight, const int& imageWidth, const int& bucketSize, int cpuThreadsCount, std::vector<std::vector<ColorRGB>>& pixelMatrix) {
	BucketArray(imageHeight, imageWidth, bucketSize);
	for (int i = 0; i < cpuThreadsCount; ++i) {
		threads.emplace_back(std::thread(&BucketGenerator::createBucketArray, this, std::ref(render), std::ref(imageHeight), std::ref(imageWidth), std::ref(bucketSize), std::ref(pixelMatrix)));
	}

	// Wait for all threads to finish
	for (auto& thread : threads) {
		thread.join();
	}
}

void BucketGenerator::BucketArray(const int& imageHeight, const int& imageWidth, const int& bucketSize) {
	int startX = 0;
	int endX = bucketSize;

	int startY = 0;
	int endY = 0;
	for (;;) {
		for (;;) {
			startY = endY;
			endY = endY + bucketSize;
			buckets.emplace_back(Bucket(startX, endX, startY, endY));
			if (endY >= imageWidth) break;
		}
		startX = endX;
		endX = endX + bucketSize;
		startY = 0;
		endY = 0;
		if (endX > imageHeight) break;
	}
}