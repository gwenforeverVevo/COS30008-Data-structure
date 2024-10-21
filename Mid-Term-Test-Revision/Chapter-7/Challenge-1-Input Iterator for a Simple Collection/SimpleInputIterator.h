
#ifndef SIMPLE_INPUT_ITERATOR_H
#define SIMPLE_INPUT_ITERATOR_H

#include <vector>

class SimpleInputIterator
{
private:
    const std::vector<int> &data;
    size_t position;

public:
    SimpleInputIterator(const std::vector<int> &collection); // Constructor

    // Dereference operator to access the current element
    const int &operator*() const;

    // Pre-increment operator
    SimpleInputIterator &operator++();

    // Equality and inequality operators
    bool operator==(const SimpleInputIterator &other) const;
    bool operator!=(const SimpleInputIterator &other) const;
};

#endif // SIMPLE_INPUT_ITERATOR_H
