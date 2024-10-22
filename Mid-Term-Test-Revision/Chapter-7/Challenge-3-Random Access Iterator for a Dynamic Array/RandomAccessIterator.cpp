#include "RandomAccessIterator.h"

using namespace std;

RandomAccessIterator::RandomAccessIterator(int *array, size_t pos) : data(array), position(pos)
{
}

int &RandomAccessIterator::operator*() const
{

    return data[position];
}

int &RandomAccessIterator::operator[](size_t index) const
{

    if (index >= position)  // Assuming position represents the total size of the array
    {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

RandomAccessIterator &RandomAccessIterator::operator++()
{
    ++position;
    return *this;
}
RandomAccessIterator &operator--()
{
    --position;
    return *this;
}

RandomAccessIterator &RandomAccessIterator::operator+=(size_t n)
{

    position += n;
    return *this;
}
RandomAccessIterator &RandomAccessIterator::operator-=(size_t n)
{
    position -= n;
    return *this;
}

bool RandomAccessIterator::operator==(const RandomAccessIterator &other) const
{
    return position == other.position;
}
bool RandomAccessIterator::operator!=(const RandomAccessIterator &other) const
{
    return !(position == other.position);
}
bool RandomAccessIterator::operator<(const RandomAccessIterator &other) const
{
    return position < other.position;
}
bool RandomAccessIterator::operator>(const RandomAccessIterator &other) const
{
    return position > other.position;
}

size_t RandomAccessIterator::operator-(const RandomAccessIterator &other) const
{
    return position - other.position;
}
