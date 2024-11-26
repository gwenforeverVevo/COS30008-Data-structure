#ifndef CIRCULAR_LINKED_LIST_TEMPLATE_H
#define CIRCULAR_LINKED_LIST_TEMPLATE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class CircularLinkedList {
private:
    // Node structure
    struct Node {
        T data;       // Data stored in the node
        Node* next;   // Pointer to the next node

        // Node constructor
        Node(const T& value, Node* nextNode = nullptr)
            : data(value), next(nextNode) {}
    };

    Node* tail; // Pointer to the last node (helps manage circular structure)
    int size;   // Number of elements in the list

public:
    // Constructor
    CircularLinkedList();

    // Destructor
    ~CircularLinkedList();

    // Add an element at the front
    void push_front(const T& value);

    // Add an element at the back
    void push_back(const T& value);

    // Remove an element from the front
    void pop_front();

    // Remove an element from the back
    void pop_back();

    // Check if the list is empty
    bool isEmpty() const;

    // Get the size of the list
    int getSize() const;

    // Iterator class for traversing the list
    class Iterator {
    private:
        Node* current;   // Pointer to the current node
        Node* start;     // Pointer to the start of the iteration (for circular behavior)

    public:
        using IteratorType = Iterator;

        // Constructor
        Iterator(Node* node, Node* startNode);

        // Dereference operator
        const T& operator*() const;

        // Pre-increment operator
        Iterator& operator++();

        // Post-increment operator
        Iterator operator++(int);

        // Equality comparison
        bool operator==(const Iterator& aRHS) const;

        // Inequality comparison
        bool operator!=(const Iterator& aRHS) const;
    };

    // Methods to get iterators
    Iterator begin() const;
    Iterator end() const;
};

#include "CircularLinkedList.tpp" // Include implementation

#endif // CIRCULAR_LINKED_LIST_TEMPLATE_H
