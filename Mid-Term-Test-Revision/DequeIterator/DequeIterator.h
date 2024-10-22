#ifndef DEQUE_ITERATOR_H
#define DEQUE_ITERATOR_H

#include <deque>

class DequeIterator
{
private:
    std::deque<int> deque;

public:
    // Constructor
    DequeIterator(const std::deque<int> &dq);

    // Forward Iterator class
    class Iterator
    {
    private:
        std::deque<int>::iterator current;

    public:
        // Constructor
        Iterator(std::deque<int>::iterator it);

        // Dereference operator
        int &operator*() const;

        // Pre-increment and pre-decrement operators
        Iterator &operator++();
        Iterator &operator--();

        // Equality and inequality operators
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
    };

    // Begin and End functions
    Iterator begin();
    Iterator end();
};

#endif // DEQUE_ITERATOR_H
