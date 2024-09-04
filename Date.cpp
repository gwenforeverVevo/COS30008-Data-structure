#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int d, int m, int y)
    : day(d), month(m), year(y) {}

void Date::display() const {
    cout << "Date: " << day << "/" << month << "/" << year << endl;
}
