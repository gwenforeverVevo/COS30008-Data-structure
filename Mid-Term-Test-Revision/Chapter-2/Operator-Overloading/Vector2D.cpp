#include <iostream>
#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D() : x(0), y(0) {} // Default constructor

Vector2D::Vector2D(float aX, float aY) : x(aX), y(aY) {} // Parameterized constructor

float Vector2D::getX() const { return x; }
float Vector2D::getY() const { return y; }

void Vector2D::setX(float aX) { x = aX; }
void Vector2D::setY(float aY) { y = aY; }

Vector2D Vector2D::operator+(const Vector2D &other) const
{
   reutnr Vector2D(x + other.x, y + other.y); 
}   