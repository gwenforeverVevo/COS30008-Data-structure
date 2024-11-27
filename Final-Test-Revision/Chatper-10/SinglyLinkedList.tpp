#include "SinglyLinkedList.h"

// Constructor: Initialize an empty list
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
    : head(nullptr), tail(nullptr), size(0) {}

// Destructor: Clean up all dynamically allocated nodes
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    while (head != nullptr)
    {
        pop_front();
    }
}

// Copy Constructor: Perform a deep copy of another list
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList &other)
    : head(nullptr), tail(nullptr), size(0)
{
    for (Node *current = other.head; current != nullptr; current = current->next)
    {
        push_back(current->data);
    }
}

// Move Constructor: Transfer ownership of resources
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList &&other) noexcept
    : head(other.head), tail(other.tail), size(other.size)
{
    other.head = other.tail = nullptr;
    other.size = 0;
}

// Copy Assignment Operator
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(const SinglyLinkedList &other)
{
    if (this != &other)
    {
        while (!isEmpty())
        {
            pop_front();
        }
        for (Node *current = other.head; current != nullptr; current = current->next)
        {
            push_back(current->data);
        }
    }
    return *this;
}

// Move Assignment Operator
template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(SinglyLinkedList &&other) noexcept
{
    if (this != &other)
    {
        while (!isEmpty())
        {
            pop_front();
        }
        head = other.head;
        tail = other.tail;
        size = other.size;

        other.head = other.tail = nullptr;
        other.size = 0;
    }
    return *this;
}

// Add element to the front of the list
template <typename T>
void SinglyLinkedList<T>::push_front(const T &value)
{
    head = new Node(value, head);
    if (tail == nullptr)
    {
        tail = head; // First node is both head and tail
    }
    ++size;
}

// Add element to the back of the list
template <typename T>
void SinglyLinkedList<T>::push_back(const T &value)
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

// Remove the first element in the list
template <typename T>
void SinglyLinkedList<T>::pop_front()
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

// Remove the last element in the list
template <typename T>
void SinglyLinkedList<T>::pop_back()
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

// Get the size of the list
template <typename T>
int SinglyLinkedList<T>::getSize() const
{
    return size;
}

// Check if the list is empty
template <typename T>
bool SinglyLinkedList<T>::isEmpty() const
{
    return size == 0;
}

// Iterator Constructor
template <typename T>
SinglyLinkedList<T>::Iterator::Iterator(Node *node) : current(node) {}

// Dereference operator
template <typename T>
T &SinglyLinkedList<T>::Iterator::operator*() const
{
    return current->data;
}

// Pre-increment operator
template <typename T>
typename SinglyLinkedList<T>::Iterator &SinglyLinkedList<T>::Iterator::operator++()
{
    current = current->next;
    return *this;
}

// Post-increment operator
template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    current = current->next;
    return temp;
}

// Equality operator
template <typename T>
bool SinglyLinkedList<T>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

// Inequality operator
template <typename T>
bool SinglyLinkedList<T>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}

// Begin iterator
template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::begin() const
{
    return Iterator(head);
}

// End iterator
template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::end() const
{
}
