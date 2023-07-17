#pragma once
#include "Vector3d.h"
class Lights3d {
public:
    /*
    Lights3d Constructor 
        ->set position of light and intesitet
    */
    Lights3d(const Vector3d& position, const int& intensity) : position(position), intensity(intensity) {}

    /* Getters */
    inline Vector3d& getPosition() {
        return position;
    }
    
    inline const int getIntensity() {
        return intensity;
    }

    /* Setters */
    inline void setPosition(const Vector3d& position) {
        this->position = position; 
    }
    
    inline void setIntensity(const int& intensity) {
        this->intensity = intensity; 
    }
private:
    Vector3d position;
    int intensity;
};