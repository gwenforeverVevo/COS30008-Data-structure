#pragma once
#include <string>
#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int y, int m, int d);
    void display() const;
};