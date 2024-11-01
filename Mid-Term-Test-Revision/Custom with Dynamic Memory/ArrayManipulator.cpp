#include "ArrayManipulator.h"
#include <algorithm> // For std::reverse and std::sort

using namespace std;
/*
// Reverse the array
void ArrayManipulator::reverse(DynamicArray &array)
{
    std::reverse(&array[0], &array[0] + array.getSize());
}

// Sort the array in ascending order
void ArrayManipulator::sort(DynamicArray &array)
{
    std::sort(&array[0], &array[0] + array.getSize());
}

// Find the maximum value in the array
int ArrayManipulator::findMax(const DynamicArray &array) const
{
    return *std::max_element(&array[0], &array[0] + array.getSize());
}


*/
// Reverse the array manually
void ArrayManipulator::reverse(DynamicArray &array)
{
    size_t n = array.getSize();
    for (size_t i = 0; i < n / 2; i++)
    {
        // Swap elements
        int temp = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = temp;
    }
}

// Sort the array manually (using Bubble Sort)
void ArrayManipulator::sort(DynamicArray &array)
{
    size_t n = array.getSize();
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            // Swap if the current element is greater than the next one
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Find the maximum value manually
int ArrayManipulator::findMax(const DynamicArray &array) const
{
    size_t n = array.getSize();
    if (n == 0)
    {
        throw std::runtime_error("Array is empty");
    }

    // Assume the first element is the largest
    int maxVal = array[0];
    for (size_t i = 1; i < n; i++)
    {
        if (array[i] > maxVal)
        {
            maxVal = array[i];
        }
    }

    return maxVal;
}