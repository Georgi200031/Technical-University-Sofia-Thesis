#pragma once
#include <cmath>
#include <cassert>
#include "Constants.h"

class Vector3d {
public:
    /* Empty constructor */
    Vector3d();
    /* Constctor Vector3d set x,y,z*/
    Vector3d(const float& x, const float& y, const float& z);

    //function return lenght of vector
    float length() const;

    /* Some aritmetic operations */
    Vector3d operator+(const Vector3d& rhs) const;
    Vector3d operator-(const Vector3d& rhs) const;
    Vector3d operator*(const float& t) const;
    bool operator>(const Vector3d& rhs) ;
    bool operator<(const Vector3d& rhs);
    Vector3d min(const Vector3d& rhs) ;
    Vector3d max(const Vector3d& rhs) ;
    Vector3d operator/(const Vector3d& rhs) const;
    Vector3d operator/(const int& t) const;
    float& sideAxis(const int& index);
    Vector3d operator*(const Vector3d& rhs) const;
    bool isVectorNegative() const {
        return (x < 0) || (y < 0) || (z < 0);
    }
    bool operator==(const Vector3d& rhs) const;

    //function define cross product and return 3rd vector (penperdicular)
    Vector3d cross(const Vector3d& rhs) const;

    //function define dot product return number
    float dot(const Vector3d& rhs) const;

    //function normalize Vector3d and set it.
    void normalize();

    float x;
    float y;
    float z;
};