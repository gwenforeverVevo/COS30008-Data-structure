#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class DoublyLinkedList
{
private:
    // Node structure for the doubly linked list
    struct Node
    {
        T data;     // Data stored in the node
        Node *prev; // Pointer to the previous node
        Node *next; // Pointer to the next node

        // Node constructor
        Node(const T &value, Node *previousNode = nullptr, Node *nextNode = nullptr)
            : data(value), prev(previousNode), next(nextNode) {}
    };

    Node *head; // Pointer to the first node
    Node *tail; // Pointer to the last node
    int size;   // Number of elements in the list

public:
    // Constructor
    template <typename T>
    DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0)
    {
    }

    // Destructor
    template <typename T>
    DoublyLinkedList<T>::~DoublyLinkedList()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }

    // Add an element at the front of the list
    void push_front(const T &value)
    {
        Node *newNode = new Node(value, nullptr, head);
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr)
        {
            tail = head; // If the list was empty
        }
        ++size;
    }

    // Add an element at the back of the list
    template <typename T>
    void DoublyLinkedList<T>::push_back(const T &value)
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
        {
            head = tail = newNode; // First node is both head and tail
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    // Remove an element from the front of the list
    template <typename T>
    void DoublyLinkedList<T>::pop_front()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        --size;
        if (head == nullptr)
        {
            tail = nullptr; // List is now empty
        }
    }

    // Remove an element from the back of the list
    template <typename T>
    void DoublyLinkedList<T>::pop_back()
    {
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }

        --size;
    }

    // Check if the list is empty
    template <typename T>
    bool DoublyLinkedList<T>::isEmpty() const
    {
        return size == 0;
    }

    // Get the size of the list
    template <typename T>
    int DoublyLinkedList<T>::getSize() const
    {
        return size;
    }

    // Iterator class for traversing the list
    class Iterator
    {
    private:
        Node *current; // Pointer to the current node

    public:
        // Constructor
        explicit Iterator(Node *node) : current(node)
        {
        }

        // Dereference operator
        T &operator*() const
        {
            return current->data;
        }

        // Pre-increment operator (++value)
        Iterator &operator++()
        {

            current = current->next;
            return *this;
        }

        // Post-increment operator (value++)
        Iterator operator++(int)
        {
            Iterator *temp = current;
            current = current->next;
            return temp;
        }

        // Pre-decrement operator (--value)
        Iterator &operator--()
        {
            current = current->prev;
            return *this;
        }

        // Post-decrement operator (value--)
        Iterator operator--(int)
        {
            Iterator *temp = current;
            current = current->prev;
            return temp;
        }

        // Equality comparison
        bool operator==(const Iterator &other) const
        {
            return (current == other.current)
        }

        // Inequality comparison
        bool operator!=(const Iterator &other) const
        {
            return !(current == other.current)
        }
    };

    // Begin and end methods for forward iteration
    Iterator begin() const
    {
        return Iterator(head);
    }
    Iterator end() const
    {
        return current->nullptr;
    }
};

// Implementation of the template class in a separate file
#include "DoublyLinkedList.tpp"

#endif // DOUBLY_LINKED_LIST_H
