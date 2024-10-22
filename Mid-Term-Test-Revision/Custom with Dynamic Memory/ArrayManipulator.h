#ifndef ARRAY_MANIPULATOR_H
#define ARRAY_MANIPULATOR_H

#include "DynamicArray.h"

class ArrayManipulator
{
public:
    // Reverse the array
    void reverse(DynamicArray &array);

    // Sort the array in ascending order
    void sort(DynamicArray &array);

    // Find the maximum value in the array
    int findMax(const DynamicArray &array) const;
};

#endif // ARRAY_MANIPULATOR_H
