#ifndef COLLECTION_ITERATOR_H
#define COLLECTION_ITERATOR_H

#include <vector>

class CollectionIterator
{
private:
    std::vector<int> fCollection;  // A collection of integers

public:
    // Constructor to initialize with a collection of integers
    CollectionIterator(const std::vector<int> &collection);

    // Iterator class for the collection
    class Iterator
    {
    private:
        std::vector<int>::iterator current;  // Tracks the current position

    public:
        Iterator(std::vector<int>::iterator it);

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

#endif // COLLECTION_ITERATOR_H
