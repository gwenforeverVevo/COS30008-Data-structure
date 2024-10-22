#include "IndexedVector.h"

using namespace std;

IndexedVector::IndexedVector(int n) : size(n), data(n, 0)
{
}

const int &IndexedVector::operator[](int index) const
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("The index out of bounds");
    }
    return data[index];
}

int IndexedVector::getSize() const
{
    return size;
}

void IndexedVector::setValue(int index, int value)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("The index out of bounds");
    }

    data[index] = value;
}

int IndexedVector::maxElement() const
{
    // return data[size];
    return *:max_element(data.begin(), data.end());
}