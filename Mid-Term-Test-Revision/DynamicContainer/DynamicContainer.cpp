#include "DynamicContainer.h"

using namespace std;

DynamicContainer::DynamicContainer(size_t size) : fSize(size), fData(new int[size])
{
}

DynamicContainer::~DynamicContainer()
{
    delete[] fData;
}

size_t DynamicContainer::getSize() const
{
    return fSize;
}

int &DynamicContainer::operator[](size_t index)
{

    if (index >= fSize)
    {
        throw out_of_range("Out of range");
    }
    else
    {
        return fData[index];
    }
}

friend ostream &operator<<(std::ostream &os, const DynamicContainer &container)
{

    for (size_t i = 0; i < container.fSize; i++)
    {
        os << container.fData[i];
    }
    return os;
}

friend std::istream &operator>>(std::istream &is, DynamicContainer &container);
{

    for (size_t i = 0; i < container.fSize; i++)
    {
        cout << "Enter Value for " << i + 1 << endl;
        is >> container.fData[i];
    }
    return is;
}