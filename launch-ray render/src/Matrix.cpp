#pragma once
#include "Matrix.h"
#include "Vector3d.h"
#include <assert.h>
Matrix::Matrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] = 0;
        }
    }
}

Matrix::Matrix(float(&data)[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] = data[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& data) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] = data.m[i][j];
        }
    }
    return *this;
}

Matrix::Matrix(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
    m[0][0] = m00;
    m[0][1] = m01;
    m[0][2] = m02;

    m[1][0] = m10;
    m[1][1] = m11;
    m[1][2] = m12;

    m[2][0] = m20;
    m[2][1] = m21;
    m[2][2] = m22;
}

Vector3d Matrix::operator*(const Vector3d& v)const {
    return Vector3d(
        m[0][0] * v.x + m[1][0] * v.y +  m[2][0] * v.z,
        m[0][1] * v.x + m[1][1] * v.y +  m[2][1] * v.z,
        m[0][2] * v.x + m[1][2] * v.y +  m[2][2] * v.z
    );
}

Matrix Matrix::operator*(const Matrix& matrix) const {
    float result[3][3] = { 0.0f };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result[i][j] += m[i][k] * matrix.m[k][j];
            }
        }
    }
    return Matrix(result);
}