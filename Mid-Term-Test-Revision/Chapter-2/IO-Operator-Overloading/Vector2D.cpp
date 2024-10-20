#include <iostream>
#include "Vector2D.h"

using namespace std;

Vector2D(float aX, float aY) : x(aX), y(aY) {}

freind istream &operator>>(istream &input, Vector2D &vec)
{
    cout << "Enter Value of x" << endl;
    input >> vec.x;
    cout << "Enter Value of y" << endl;
    input >> vec.y;
    return input;
}

freind ostream &operator<<(ostream &output, Vector2D &vec)
{
    output << "The value of X is" << vec.x << endl;
    output << "The value of Y is" << vec.y << endl;

    return output;
}