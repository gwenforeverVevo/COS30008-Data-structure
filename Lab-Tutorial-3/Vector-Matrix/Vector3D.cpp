
#include "Vector3D.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

Vector3D::Vector3D(float aX, float aY, float aW) noexcept
    : fBaseVector(aX, aY), fW(aW) {}

Vector3D::Vector3D(const Vector2D &aVector) noexcept
    : fBaseVector(aVector), fW(1.0f) {}

float Vector3D::x() const noexcept { return fBaseVector.x(); }
float Vector3D::y() const noexcept { return fBaseVector.y(); }
float Vector3D::w() const noexcept { return fW; }

float Vector3D::operator[](size_t aIndex) const
{
    switch (aIndex)
    {
    case 0:
        return fBaseVector.x();
    case 1:
        return fBaseVector.y();
    case 2:
        return fW;
    default:
        throw std::out_of_range("Index out of range in Vector3D");
    }
}

Vector3D::operator Vector2D() const noexcept
{
    return fBaseVector;
}

Vector3D Vector3D::operator*(const float aScalar) const noexcept
{
    return Vector3D(fBaseVector.x() * scalar, fBaseVector.y * scalar, fW * scalar);
}

Vector3D Vector3D::operator+(const Vector3D &aOther) const noexcept
{
    return Vector3D(fBaseVector.x() + aOther.x(), fBaseVector.y() + aOther.y(), fW + aOther.w());
}

float Vector3D::dot(const Vector3D& aOther) const noexcept {
    return (fBaseVector.x() * aOther.x()) + (fBaseVector.y() * aOther.y()) + (fW * aOther.w());
}

std::ostream& operator<<(std::ostream& aOStream, const Vector3D& aVector) {
    aOStream << "(" << aVector.x() << ", " << aVector.y() << ", " << aVector.w() << ")";
    return aOStream;
}