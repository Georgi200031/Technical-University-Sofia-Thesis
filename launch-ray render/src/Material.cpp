#pragma once
#include "material.h"
MaterialType convertToMaterialType(const std::string& str) {
    if (str == "diffuse") {
        return MaterialType::diffuse;
    }
    else if (str == "reflective") {
        return MaterialType::reflective;
    }
    else if (str == "refractive") {
        return MaterialType::refractive;
    }
    else if (str == "constant") {
        return MaterialType::constant;
    }
    return MaterialType::background;
}
