#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

struct Node
{
    int value;
    Node *prev;
    Node *next;
};

class BidirectionalIterator
{
private:
    Node *current;  // Pointer to the current node

public:
    BidirectionalIterator(Node *startNode);  // Constructor

    // Dereference operator to access the current element
    int &operator*() const;

    // Pre-increment and pre-decrement operators
    BidirectionalIterator &operator++();
    BidirectionalIterator &operator--();

    // Post-increment and post-decrement operators
    BidirectionalIterator operator++(int);
    BidirectionalIterator operator--(int);

    // Equality and inequality operators
    bool operator==(const BidirectionalIterator &other) const;
    bool operator!=(const BidirectionalIterator &other) const;
};

#endif // BIDIRECTIONAL_ITERATOR_H
