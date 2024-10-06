#define _USE_MATH_DEFINES // must be defined before any #include
#include "Matrix3x3.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

Matrix3x3::Matrix3x3() noexcept : fRows()
{
}

Matrix3x3::Matrix3x3(const Vector3D &aRow1, const Vector3D &aRow2, const Vector3D &aRow3) noexcept
    : fRows{aRow1, aRow2, aRow3} {}

Matrix3x3 Matrix3x3::operator*(const float aScalar) const noexcept
{
    return Matrix3x3(fRows[0] * aScalar, fRows[1] * aScalar, fRows[2] * aScalar);
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &aOther) const noexcept
{
    return Matrix3x3(fRows[0] + aOther.fRows[0], fRows[1] + aOther.fRows[1], fRows[2] + aOther.fRows[2]);
}

Vector3D Matrix3x3::operator*(const Vector3D &aVector) const noexcept
{
    return Vector3D(fRows[0].dot(aVector), fRows[1].dot(aVector), fRows[2].dot(aVector));
}

Matrix3x3 Matrix3x3::scale(const float aX, const float aY)
{
    return Matrix3x3(Vector3D(aX, 0.0f, 0.0f), Vector3D(0.0f, aY, 0.0f), Vector3D(0.0f, 0.0f, 1.0f));
}

Matrix3x3 Matrix3x3::translate(const float aX, const float aY)
{
    return Matrix3x3(Vector3D(1.0f, 0.0f, aX), Vector3D(0.0f, 1.0f, aY), Vector3D(0.0f, 0.0f, 1.0f));
}

Matrix3x3 Matrix3x3::rotate(const float aAngleInDegree)
{
    float radian = aAngleInDegree * (M_PI / 180.0f);
    return Matrix3x3(Vector3D(std::cos(radian), -std::sin(radian), 0.0f),
                     Vector3D(std::sin(radian), std::cos(radian), 0.0f),
                     Vector3D(0.0f, 0.0f, 1.0f));
}

const Vector3D Matrix3x3::row(size_t aRowIndex) const
{
    if (aRowIndex >= 3)
        throw std::out_of_range("Invalid row index");
    return fRows[aRowIndex];
}

const Vector3D Matrix3x3::column(size_t aColumnIndex) const
{
    if (aColumnIndex >= 3)
        throw std::out_of_range("Invalid column index");

    return Vector3D(fRows[0][aColumnIndex], fRows[1][aColumnIndex], fRows[2][aColumnIndex]);
}