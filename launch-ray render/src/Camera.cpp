#pragma once
#include "Camera.h"


/* SETTERS */
void Camera::setPosition(const Vector3d& position) {
    this->position = position;
}

void Camera::setRotationMatrix( Matrix rotationMatrix) {
    this->rotationMatrix = rotationMatrix;
}
    
/* GETTERS */
Vector3d Camera::getPosition() const { 
    return  position; 
}

Matrix Camera::getRotationMatrix() const { 
    return rotationMatrix; 
}
float Camera::getFovAngle() const {
	return fovAngle;
}

void Camera::dolly(const float& distance)  {
	Vector3d moveDir = rotationMatrix * Vector3d(0, 0, distance);
	position = position + moveDir;
}

void Camera::truck(const float& distance) {
	Vector3d moveDir = rotationMatrix * Vector3d(distance, 0, 0);
	position = position + moveDir;

}

void Camera::pedestal(const float& distance) {
	Vector3d moveDir = rotationMatrix * Vector3d(0, distance, 0);
	position = position + moveDir;
}

void Camera::FOV(const float& fovAngle) {
	this->fovAngle = fovAngle;
}

void Camera::pan(const float& angle) {
	const float radios = angle * (PI / 180.f);
	const Matrix generateRotationY(
		cosf(radios), 0.f, -sinf(radios),
		0.f, 1.f, 0.f,
		sinf(radios), 0.f, cosf(radios)
	);
	rotationMatrix = rotationMatrix * generateRotationY;	
}

void Camera::tilt(const float& angle) {
	const float radios = angle * (PI / 180.f);
	const Matrix generateRotationX(
		1.f, 0.f, 0.f,
		0.f, cosf(radios), -sinf(radios),
		0.f, sinf(radios), cosf(radios)
	);
	rotationMatrix = rotationMatrix * generateRotationX;
}

void Camera::roll(const float& angle) {
	const float radios = angle * (PI / 180.f);
	const Matrix generateRotationZ(
		cosf(radios), -sinf(radios), 0.f,
		sinf(radios), cosf(radios), 0.f,
		0.f, 0.f, 1.f
	);
	rotationMatrix = rotationMatrix * generateRotationZ;
}
