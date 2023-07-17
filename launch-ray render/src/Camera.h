#pragma once
#include "Matrix.h"
#include <math.h>
class Camera {
public:
    /*
	 Class to represent camera and operations.
	 camera coordinate system:
	   - Right-handed coordinate system;
	   - X-axis point to the right of the camera;
	   - Y-axis point up from the camera;
	   - Z-axis points back from the camera.
	 Here the camera always looks at Z-axis.   
    */
    //Default camera is centred at the origin.
    Camera() :position(0, 0, 0), rotationMatrix(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f) {}
    Camera(const Vector3d& position, const Matrix& rotationMatrix) : position(position), rotationMatrix(rotationMatrix) {};

    /* SETTERS */
    void setPosition(const Vector3d& position);
    void setRotationMatrix( Matrix rotationMatrix);
    
    /* GETTERS */
    Vector3d getPosition() const;
    Matrix getRotationMatrix() const;
    float getFovAngle() const;

	//Move the camera along Z-axis. => forward-backward
	//Positive distance = move camera forward. 
    void dolly(const float& dist);
    
    void FOV(const float& fovAbgle);

    //Move the camera along X-axis. => left-right
	//Positive distance = move camera right
    void truck(const float& dist);

    //Move the camera along Y-axis. => up-down
	//Positive distatnce = move camera up
    void pedestal(const float& dist);

    //Rotate the camera about Y-axis, left-right by angle
	//Positive angle = rotate camera left
    void pan(const float& angle);
    
    //Rotate the camera about X axis, up-down  by angle
    //Positive angle = rotate camera up
    void tilt(const float& angle);

    //Rotate the camera about Z-axis,
	//Positive angle = rotate camera horizontally to the left or to the right around th z-axis.
    void roll(const float& angle);


private:
    Vector3d position;
    Matrix rotationMatrix;
    float fovAngle = 0;//fovAngle for Fov view (by default is zero i.e not have fov)
};