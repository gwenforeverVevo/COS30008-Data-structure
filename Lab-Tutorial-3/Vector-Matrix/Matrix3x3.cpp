#define _USE_MATH_DEFINES // must be defined before any #include
#include "Matrix3x3.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

Matrix3x3::Matrix3x3() noexcept : fRows()
{
}

Matrix3x3 &Matrix3x3::operator*(const float aScalar) const noexcept
{
    return Matrix3x3(fRows[0] * aScalar, fRows[1] * aScalar, fRows[2] * aScalar);
}

Matrix3x3 &Matrix3x3::operator+(const Matrix3x3 &aVector) const noexcept
{
    return Matrix3x3(fRows[0] + aOther.fRows[0], fRows[1] + aOther.fRows[1], fRows[2] + aOther.fRows[2]);
}

Vector &Matrix3x3::operator*(const Vector3D &aVector) const noexcept
{
    return Vector3D(fRows[0].dot(aVector), fRows[1].dot(aVector), fRows[2].dot(aVector));
}
