#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>
#include <algorithm> // For std::sort

using namespace std;

// Constructor to allocate dynamic memory
DynamicArray::DynamicArray(size_t size) : size(size), data(new int[size])
{
}

// Destructor to release dynamically allocated memory
DynamicArray::~DynamicArray()
{
    delete[] data;
}

// Get the size of the array
size_t DynamicArray::getSize() const
{
    return size;
}

// Overload index operator with bounds checking
int &DynamicArray::operator[](size_t index)
{
    if (index >= size)
    {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

// Overload output stream operator to print the array
ostream &operator<<(ostream &os, const DynamicArray &array)
{
    for (size_t i = 0; i < array.size; i++)
    {
        os << array.data[i] << " ";
    }
    return os;
}

// Overload input stream operator to input data into the array
istream &operator>>(istream &is, DynamicArray &array)
{
    for (size_t i = 0; i < array.size; i++)
    {
        cout << "Enter value for element " << i + 1 << ": ";
        is >> array.data[i];
    }
    return is;
}
