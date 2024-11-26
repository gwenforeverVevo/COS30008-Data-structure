#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

// Template class for a singly linked list
template <typename T>
class SinglyLinkedList {
private:
    // Node structure
    struct Node {
        T data;
        Node* next;

        // Node constructors
        Node(const T& value, Node* nextNode = nullptr)
            : data(value), next(nextNode) {}

        Node(T&& value, Node* nextNode = nullptr)
            : data(std::move(value)), next(nextNode) {}
    };

    Node* head; // Pointer to the first node
    Node* tail; // Pointer to the last node
    int size;   // Number of nodes in the list

public:
    // Constructor
    SinglyLinkedList();

    // Destructor
    ~SinglyLinkedList();

    // Copy constructor
    SinglyLinkedList(const SinglyLinkedList& other);

    // Move constructor
    SinglyLinkedList(SinglyLinkedList&& other) noexcept;

    // Copy assignment operator
    SinglyLinkedList& operator=(const SinglyLinkedList& other);

    // Move assignment operator
    SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept;

    // Add element at the front
    void push_front(const T& value);

    // Add element at the back
    void push_back(const T& value);

    // Remove element from the front
    void pop_front();

    // Remove element from the back
    void pop_back();

    // Get the size of the list
    int getSize() const;

    // Check if the list is empty
    bool isEmpty() const;

    // Iterator class for traversing the list
    class Iterator {
    private:
        Node* current; // Pointer to the current node

    public:
        // Constructor
        explicit Iterator(Node* node);

        // Dereference operator
        T& operator*() const;

        // Pre-increment operator
        Iterator& operator++();

        // Post-increment operator
        Iterator operator++(int);

        // Equality comparison
        bool operator==(const Iterator& other) const;

        // Inequality comparison
        bool operator!=(const Iterator& other) const;
    };

    // Begin and end methods for iteration
    Iterator begin() const;
    Iterator end() const;
};

#include "SinglyLinkedList.tpp" // Include template implementation

#endif // SINGLY_LINKED_LIST_H
