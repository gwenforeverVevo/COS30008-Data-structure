#ifndef RANDOM_ACCESS_ITERATOR_H
#define RANDOM_ACCESS_ITERATOR_H

class RandomAccessIterator
{
private:
    int *data;  // Pointer to the array
    size_t position;  // Current position in the array

public:
    RandomAccessIterator(int *array, size_t pos);  // Constructor

    // Dereference operator
    int &operator*() const;

    // Indexing operator to access elements by index
    int &operator[](size_t index) const;

    // Pre-increment and pre-decrement operators
    RandomAccessIterator &operator++();
    RandomAccessIterator &operator--();

    // Compound assignment operators
    RandomAccessIterator &operator+=(size_t n);
    RandomAccessIterator &operator-=(size_t n);

    // Comparison operators
    bool operator==(const RandomAccessIterator &other) const;
    bool operator!=(const RandomAccessIterator &other) const;
    bool operator<(const RandomAccessIterator &other) const;
    bool operator>(const RandomAccessIterator &other) const;

    // Distance between iterators
    size_t operator-(const RandomAccessIterator &other) const;
};

#endif // RANDOM_ACCESS_ITERATOR_H
