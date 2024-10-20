#include <iostream>
#include "Vector2D.h"
#include <cmath> 

using namespace std;

Vector2D(float aX, float aY) : x(aX), y(aY) {}

float distanceBetween(const Vector2D &a, const Vector2D &b) {
    // Calculate and return the Euclidean distance between 'a' and 'b'
    float total;
    float deltaX = b.x - a.x;  // Difference in x coordinates
    float deltaY = b.y - a.y;  // Difference in y coordinates
    return sqrt(deltaX * deltaX + deltaY * deltaY);  // Return the Euclidean distance
}