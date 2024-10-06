
// COS30008, tutorial 3, 2024

#define _USE_MATH_DEFINES 
#include <cmath>        
#include <iostream>

#include "Vector2D.h"
#include "Vector3D.h"
#include "Matrix3x3.h"
using namespace std;

void runP1();

int main()
{
    Vector2D a(1.0f, 2.0f);
    Vector2D b(1.0f, 4.0f);
    Vector2D c(-2.0f, 3.0f);
    Vector2D d(0.0f, 0.0f);

    cout << "Test vector implementation: " << endl;
    cout << "Vector a = " << a << endl;
    cout << "Vector b = " << b << endl;
    cout << "Vector c = " << c << endl;
    cout << "Vector d = " << d << endl;

    Vector3D a3(a);
    Vector3D b3(b);
    Vector3D c3(c);
    Vector3D d3(d);

    cout << "Vector a3 = " << a << endl;
    cout << "Vector b3 = " << b << endl;
    cout << "Vector c3 = " << c << endl;
    cout << "Vector d3 = " << d << endl;

    cout << "Test homogeneous vectors:" << endl;
    cout << "Vector " << a3 << " * 3.0 = " << a3 * 3.0f << endl;
    cout << "Vector " << a3 << " + " << b3 << " = " << a3 + b3 << endl;
    cout << "Vector " << a3 << " . " << b3 << " = " << a3.dot(b3) << endl;
    cout << "Vector " << a3 << "[0] = " << a3[0] << " <=> " << a3 << ".x() = " << a3.x() << endl;
    cout << "Vector " << a3 << "[1] = " << a3[1] << " <=> " << a3 << ".y() = " << a3.y() << endl;
    cout << "Vector " << a3 << "[2] = " << a3[2] << " <=> " << a3 << ".w() = " << a3.w() << endl;

    cout << "Test 3x3 matrix:" << endl;

    Matrix3x3 ma(Vector3D(1.0f, 1.0f), Vector3D(1.0f, 1.0f), Vector3D(1.0f, 1.0f));

    cout << "ma: row 1 = " << ma.row(0) << endl;
    cout << "ma: row 2 = " << ma.row(1) << endl;
    cout << "ma: row 3 = " << ma.row(2) << endl;

    Matrix3x3 mb = ma * 2.0f;

    cout << "mb: row 1 = " << mb.row(0) << endl;
    cout << "mb: row 2 = " << mb.row(1) << endl;
    cout << "mb: row 3 = " << mb.row(2) << endl;

    Matrix3x3 mc = mb + ma;

    cout << "mc: row 1 = " << mc.row(0) << endl;
    cout << "mc: row 2 = " << mc.row(1) << endl;
    cout << "mc: row 3 = " << mc.row(2) << endl;

    Matrix3x3 lScale = Matrix3x3::scale(3.2f, 3.2f);
    Matrix3x3 lRotate = Matrix3x3::rotate(90.0f);
    Matrix3x3 lTranslate = Matrix3x3::translate(4.0f, -1.0f);

    cout << "Scale " << a3 << " by " << 3.2f << " = " << lScale * a3 << endl;
    cout << "Rotate " << b3 << " by " << 90.0f << " degrees = " << lRotate * b3 << endl;
    cout << "Translate " << c3 << " by " << lTranslate.column(2) << " = " << lTranslate * c3 << endl;
    cout << "Translate " << d3 << " by " << lTranslate.column(2) << " = " << lTranslate * d3 << endl;

    runP1();
    return 0;
}

void runP1()
{
    Vector3D a(1.0f, 2.0f, 3.0f);
    Vector3D b(static_cast<float>(M_PI), static_cast<float>(M_PI), static_cast<float>(M_PI));
    Vector3D c(1.23456789f, 9.876543210f, 12435.0987654321f);

    cout << "Vector a: " << a.toString() << endl;
    cout << "Vector b: " << b.toString() << endl;
    cout << "Vector c: " << c.toString() << endl;
}
