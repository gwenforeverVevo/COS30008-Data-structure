#ifndef FORWARD_ITERABLE_H
#define FORWARD_ITERABLE_H

#include <list>

class ForwardIterable
{
private:
    std::list<int> data;  // A collection of integers

public:
    // Constructor to initialize with a list of integers
    ForwardIterable(const std::list<int> &list);

    // Forward Iterator class for this collection
    class Iterator
    {
    private:
        std::list<int>::iterator current;

    public:
        Iterator(std::list<int>::iterator it);

        // Dereference operator to access the current element
        int &operator*() const;

        // Pre-increment operator
        Iterator &operator++();

        // Equality and inequality operators
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
    };

    // Begin and End functions to return iterators
    Iterator begin();
    Iterator end();
};

#endif // FORWARD_ITERABLE_H
