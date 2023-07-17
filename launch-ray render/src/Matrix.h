#pragma once 
#include "Vector3d.h"
/// <summary>
///   Class to represent a 3x3 matrix. The matrix is stored in column-major form in memory.
///   Matrix - Matrix and Matrix - Vector multiplicaiton must be read from right to left.
/// </summary>
class Matrix {
public:
    /* CONSTRUCORS */
    //Zero constructor
    Matrix();
    // The matrix entries are initialized to a set of values.
    Matrix(float a00, float a01, float a02, float a10, float a11, float a12, float a20, float a21, float a22);
    
    //The matrix is initialized to another matrix.
    Matrix(float(&data)[3][3]);

    /* ARITMETIC OPERATORS */

    Matrix& operator=(const Matrix& data);
    Vector3d operator*(const Vector3d& v) const;
    Matrix operator*(const Matrix& m) const;
    
private:
    float m[3][3];
};
