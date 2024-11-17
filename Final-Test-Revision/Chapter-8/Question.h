#include <iostream>
#include <stdexcept>

template <class T>
class SinglyLinkedList
{
public:
    T fValue;
    SinglyLinkedList *fNext;

    // Constructor for lvalue reference
    SinglyLinkedList(const T &aValue, SinglyLinkedList *aNext = nullptr)
        : fValue(aValue), fNext(aNext) {}

    // Constructor for rvalue reference
    SinglyLinkedList(T &&aValue, SinglyLinkedList *aNext = nullptr)
        : fValue(std::move(aValue)), fNext(aNext) {}
};

// Function to add a node to the back of the list
template <class T>
void addToBack(SinglyLinkedList<T> *&head, const T &value)
{
    if (!head)
    {
        head = new SinglyLinkedList<T>(value);
    }
    else
    {
        SinglyLinkedList<T> *current = head;
        while (current->fNext)
        {
            current = current->fNext;
        }
        current->fNext = new SinglyLinkedList<T>(value);
    }
}

// Function to add a node to the front of the list
template <class T>
void addToFront(SinglyLinkedList<T> *&head, const T &value)
{
    head = new SinglyLinkedList<T>(value, head);
}

// Function to remove a node from the back of the list
template <class T>
void removeFromBack(SinglyLinkedList<T> *&head)
{
    if (!head)
    {
        throw std::runtime_error("List is empty, cannot remove from back.");
    }
    if (!head->fNext)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        SinglyLinkedList<T> *current = head;
        while (current->fNext->fNext)
        {
            current = current->fNext;
        }
        delete current->fNext;
        current->fNext = nullptr;
    }
}

// Function to remove a node from the front of the list
template <class T>
void removeFromFront(SinglyLinkedList<T> *&head)
{
    if (!head)
    {
        throw std::runtime_error("List is empty, cannot remove from front.");
    }
    SinglyLinkedList<T> *temp = head;
    head = head->fNext;
    delete temp;
}

// Function to insert a node at a given position
template <class T>
void insertAtPosition(SinglyLinkedList<T> *&head, const T &value, int position)
{
    if (position == 0)
    {
        addToFront(head, value);
        return;
    }
    SinglyLinkedList<T> *current = head;
    for (int i = 0; i < position - 1; ++i)
    {
        if (!current)
        {
            throw std::runtime_error("Position out of bounds.");
        }
        current = current->fNext;
    }
    current->fNext = new SinglyLinkedList<T>(value, current->fNext);
}

// Function to display all nodes in the list
template <class T>
void displayList(SinglyLinkedList<T> *head)
{
    SinglyLinkedList<T> *current = head;
    while (current)
    {
        std::cout << current->fValue << " -> ";
        current = current->fNext;
    }
    std::cout << "null" << std::endl;
}

// Main method to demonstrate the list operations
int main()
{
    SinglyLinkedList<int> *list = nullptr;

    // Add nodes to the back of the list
    addToBack(list, 10);
    addToBack(list, 20);
    addToBack(list, 30);

    std::cout << "After adding nodes to the back:\n";
    displayList(list);

    // Add a node to the front of the list
    addToFront(list, 5);
    std::cout << "After adding a node to the front:\n";
    displayList(list);

    // Remove a node from the back of the list
    removeFromBack(list);
    std::cout << "After removing a node from the back:\n";
    displayList(list);

    // Remove a node from the front of the list
    removeFromFront(list);
    std::cout << "After removing a node from the front:\n";
    displayList(list);

    // Insert a node at a given position
    insertAtPosition(list, 15, 1);
    std::cout << "After inserting a node at position 1:\n";
    displayList(list);

    return 0;
}
