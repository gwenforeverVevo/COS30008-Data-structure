#ifndef DOUBLY_LINKED_LIST_TEMPLATE_H
#define DOUBLY_LINKED_LIST_TEMPLATE_H

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

        // Constructor for the Node
        Node(const T &value, Node *previousNode = nullptr, Node *nextNode = nullptr)
            : data(value), prev(previousNode), next(nextNode) {}
    };

    Node *head; // Pointer to the first node
    Node *tail; // Pointer to the last node
    int size;   // Number of elements in the list

public:
    // Constructor
    template <typename T>
    DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

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
    template <typename T>
    void DoublyLinkedList<T>::push_front(const T &value)
    {
        if (head != nullptr)
        {
            head->prev = newNode;
        }
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
        if (head == nullptr)
        {
            throw std::underflow_error("List is empty.");
        }
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
        if (head == nullptr)
        {
            throw std::underflow_error("List is empty.");
        }
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

    // Iterator class for forward and backward traversal
    class Iterator
    {
    private:
        using ListNode = Node;  // Alias for the Node type
        const ListNode *fList;  // Pointer to the current node in the list
        const ListNode *fIndex; // Pointer for additional control

    public:
        using IteratorType = Iterator;

        // Constructor
        template <typename T>
        Iterator<T>::Iterator(const ListNode *aList, const ListNode *aIndex = nullptr) : fList(aList), fIndex(aIndex)
        {
        }

        // Dereference operator
        const T &operator*() const
        {
            return fIndex->data;
        }

        // Pre-increment operator
        Iterator &operator++()
        {
            fIndex = fIndex->next;
            return *this;
        }

        // Post-increment operator
        Iterator operator++(int)
        {
            Iterator temp = *this;
            fIndex = fIndex->next;
            return temp;
        }

        // Pre-decrement operator
        Iterator &operator--()
        {
            fIndex =fIndex->prev;
            return *this;
        }

        // Post-decrement operator
        Iterator operator--(int)
        {
            Iterator temp = *this;
            fIndex =fIndex->prev;
            return temp;
        }

        // Equality comparison
        bool operator==(const Iterator &aRHS) const
        {
            return fList == aRHSfList &&
                   fIndex == aRHS.fIndex;
        }

        // Inequality comparison
        bool operator!=(const Iterator &aRHS) const
        {
            return !(*this == aRHS);
        }

        // Begin and end functions for range-based loops
        static Iterator begin(const ListNode *aList)
        {
            // Iterator iter = *this;
            // iter.fIndex = iter.fList;
            // return iter;
            return Iterator(aList, aList);
        }
        static Iterator end()
        {
            // Iterator iter = *this;
            // iter.fIndex = nullptr;
            // return iter;
            return Iterator(nullptr, nullptr);
        }
    };

    // Methods to get iterators
