
// COS30008, 2024

#define _USE_MATH_DEFINES // must be defined before any #include
#include "Polygon.h"

#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

Polygon::Polygon() noexcept : fNumberOfVertices()
{
}

void Polygon::readData(std::istream &aIStream)
{
    Vector2D vertex;
    while (aIStream >> fVertices[fNumberOfVertices])
    {
        fNumberOfVertices++;
    }
}

size_t Polygon::getNumberOfVertices() const noexcept
{
    return fNumberOfVertices;
}

const Vector2D &Polygon::getVertex(size_t aIndex) const
{
    assert(aIndex < fNumberOfVertices);

    return fVertices[aIndex];
}

float Polygon::getPerimeter() const noexcept
{
    float Result = 0.0f;
    if (fNumberOfVertices > 2)
    {
        for (size_t i = 1; i < fNumberOfVertices; i++)
        {
            Result += (fVertices[i] - fVertices[i - 1]).length();
        }

        Result += (fVertices[0] - fVertices[fNumberOfVertices - 1]).length();
    }
    return Result;
}

Polygon Polygon::scale(float aScalar) const noexcept
{
    Polygon Result = *this;

    for (size_t i = 0; i < fNumberOfVertices; i++)
    {
        Result.fVertices[i] = fVertices[i] * aScalar;
    }

    return Result;
    
}