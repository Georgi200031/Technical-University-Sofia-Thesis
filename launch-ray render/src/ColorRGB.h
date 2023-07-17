#pragma once
#include "Vector3d.h"

struct ColorRGB {
public:
    int R, G, B;
    ColorRGB() : R { 0 }, G { 0 }, B{ 0 } {}
    ColorRGB(int R, int G, int B) : R{R}, G{G}, B{B} {}
    //operator "=" for color assignment 
    inline ColorRGB& operator=(const ColorRGB& color) {
      R = color.R;
      G = color.G;
      B = color.B;
      return *this;
    }
    //operator "*" for multiply ColorRGB and floatNum then return ColorRGB
    inline ColorRGB& operator*(const float& floatNum) {
        R = static_cast<int>(floatNum * R);
        G = static_cast<int>(floatNum * G);
        B = static_cast<int>(floatNum * B);
        return *this;
    }
    //operator "*" for multiply ColorRGB and ColorRGB then return ColorRGB
    inline ColorRGB& operator*(const ColorRGB& color) {
        R = static_cast<int>(color.R * R);
        G = static_cast<int>(color.G * G);
        B = static_cast<int>(color.B * B);
        return *this;
    }
    inline ColorRGB& operator/(const int& t) {
        R = static_cast<int>(R / t);
        G = static_cast<int>(G / t);
        B = static_cast<int>(B / t);
        return *this;
    }
    //operator "*" for multiply ColorRGB and Vector3d then return ColorRGB
    inline ColorRGB& operator*(const Vector3d& color) {
        R = static_cast<int>(color.x * R);
        G = static_cast<int>(color.y * G);
        B = static_cast<int>(color.z * B);
        return *this;
    }
    //operator "+" for multiply ColorRGB and ColorRGB then return ColorRGB
    inline ColorRGB& operator+(const ColorRGB& colorFloat) {
        R = static_cast<int>(colorFloat.R + R);
        G = static_cast<int>(colorFloat.G + G);
        B = static_cast<int>(colorFloat.B + B);
        return *this;
    }
    //this constructor is for get Vector as a color and multiply each coordinates by maxColorComponent
    inline ColorRGB(const Vector3d& colorFloat) {
      int xColorInt = static_cast<int>(colorFloat.x * maxColorComponent);
      int yColorInt = static_cast<int>(colorFloat.y * maxColorComponent);
      int zColorInt = static_cast<int>(colorFloat.z * maxColorComponent);
      if (xColorInt > maxColorComponent) xColorInt = maxColorComponent;
      if (yColorInt > maxColorComponent) yColorInt = maxColorComponent;
      if (zColorInt > maxColorComponent) zColorInt = maxColorComponent;

      R = static_cast<unsigned char>(xColorInt);
      G = static_cast<unsigned char>(yColorInt);
      B = static_cast<unsigned char>(zColorInt);
    }
};