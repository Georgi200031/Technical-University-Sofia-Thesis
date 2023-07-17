
//#pragma once
#include <iostream>
#include "Vector3d.h"
#include "Constants.h"
Vector3d::Vector3d() : x(0), y(0), z(0) {}

Vector3d::Vector3d(const float& x, const float& y, const float& z) : x(x), y(y), z(z) {}

float Vector3d::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3d Vector3d::operator+(const Vector3d& rhs) const {
    return Vector3d(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3d Vector3d::operator-(const Vector3d& rhs) const {
    return Vector3d(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3d Vector3d::operator*(const float& t) const {
    return Vector3d(x * t, y * t, z * t);
}

bool Vector3d::operator==(const Vector3d& rhs) const {
    return (x == rhs.x && y == rhs.y && z == rhs.z);
}
Vector3d Vector3d::operator*(const Vector3d& rhs) const {
    return Vector3d(x * rhs.x, y * rhs.y, z * rhs.z);

}


Vector3d Vector3d::operator/(const int& t) const {
    return Vector3d(x / t, y / t, z / t);
}

Vector3d Vector3d::cross(const Vector3d& rhs) const {
    return Vector3d(
        y * rhs.z - z * rhs.y,
        z * rhs.x - x * rhs.z,
        x * rhs.y - y * rhs.x
    );
}

Vector3d Vector3d::operator/(const Vector3d& rhs) const {
    return Vector3d(x / rhs.x, y / rhs.y, z / rhs.z);
}

float& Vector3d::sideAxis(const int& index) {
    if(index == 0)
        return x;
    if (index == 1)
        return y;
    if (index == 2)
        return z;
    std::cout << "Err sideAxis input" << std::endl;
    throw std::runtime_error("Invalid sideAxis input");
}

float Vector3d::dot(const Vector3d& rhs) const {
    return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
}

Vector3d Vector3d::min(const Vector3d& rhs)  {
    if (x >= rhs.x) {
        x = rhs.x;
    }

    if (y >= rhs.y) {
        y = rhs.y;
    }

    if (z >= rhs.z) {
        z = rhs.z;
    }
    return Vector3d(x, y, z);

}
bool Vector3d::operator>(const Vector3d& rhs) {
    if (x > rhs.x && y > rhs.y && z > rhs.z) {
        return true;
    }
    return false;
}
bool Vector3d::operator<(const Vector3d& rhs) {
    if (x < rhs.x && y < rhs.y && z < rhs.z) {
        return true;
    }
    return false;
}
Vector3d Vector3d::max(const Vector3d& rhs)  {
    if (x <= rhs.x) {
        x = rhs.x;
    }

    if (y <= rhs.y) {
        y = rhs.y;
    }

    if (z <= rhs.z) {
        z = rhs.z;
    }
    return Vector3d(x, y, z);
}

void Vector3d::normalize() {
    float len = length();
    assert(std::abs(len) > EPSILON);
    float coeff = 1.0f / len;
    x *= coeff;
    y *= coeff;
    z *= coeff;
}