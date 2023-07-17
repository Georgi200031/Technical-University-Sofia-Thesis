#pragma once
//structure to store Bary Coordinates
struct BaryCoords {
public:
	BaryCoords(float u, float v) :u(u), v(v) {}
	float u;
	float v;
};