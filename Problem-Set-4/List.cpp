#include "List.h"
#include <stdexcept>  // for std::out_of_range

// Constructor: Initializes an empty list
template <typename T>
List<T>::List() noexcept : fHead(nullptr), fTail(nullptr), fSize(0) {}

// Copy constructor
template <typename T>
List<T>::List(const List& aOther) : fHead(nullptr), fTail(nullptr), fSize(0) {
    for (const auto& item : aOther) {
        push_back(item);
    }
}

// Copy assignment
template <typename T>
List<T>& List<T>::operator=(const List& aOther) {
    if (this != &aOther) {
        List temp(aOther);
        swap(temp);
    }
    return *this;
}

// Move constructor
template <typename T>
List<T>::List(List&& aOther) noexcept : fHead(aOther.fHead), fTail(aOther.fTail), fSize(aOther.fSize) {
    aOther.fHead = nullptr;
    aOther.fTail = nullptr;
    aOther.fSize = 0;
}

// Move assignment
template <typename T>
List<T>& List<T>::operator=(List&& aOther) noexcept {
    if (this != &aOther) {
        swap(aOther);
        aOther.fHead = nullptr;
        aOther.fTail = nullptr;
        aOther.fSize = 0;
    }
    return *this;
}

// Swap function
template <typename T>
void List<T>::swap(List& aOther) noexcept {
    std::swap(fHead, aOther.fHead);
    std::swap(fTail, aOther.fTail);
    std::swap(fSize, aOther.fSize);
}

// Returns the size of the list
template <typename T>
size_t List<T>::size() const noexcept {
    return fSize;
}

// Adds an element at the front of the list
template <typename T>
template <typename U>
void List<T>::push_front(U&& aData) {
    Node newNode = Node::makeNode(std::forward<U>(aData));
    if (!fHead) {
        fHead = fTail = newNode; // List is empty
    } else {
        newNode->fNext = fHead;
        fHead->fPrevious = newNode;
        fHead = newNode;
    }
    fSize++;
}

// Adds an element at the back of the list
template <typename T>
template <typename U>
void List<T>::push_back(U&& aData) {
    Node newNode = Node::makeNode(std::forward<U>(aData));
    if (!fTail) {
        fHead = fTail = newNode; // List is empty
    } else {
        newNode->fPrevious = fTail;
        fTail->fNext = newNode;
        fTail = newNode;
    }
    fSize++;
}

// Removes the first occurrence of a given element
template <typename T>
void List<T>::remove(const T& aElement) noexcept {
    Node current = fHead;
    while (current) {
        if (current->fData == aElement) {
            if (current == fHead) {
                fHead = current->fNext;
                if (fHead) fHead->fPrevious.reset();
            }
            if (current == fTail) {
                fTail = current->fPrevious.lock();
                if (fTail) fTail->fNext.reset();
            }
            current->isolate();
            fSize--;
            return;
        }
        current = current->fNext;
    }
}

// Accesses an element by index
template <typename T>
const T& List<T>::operator[](size_t aIndex) const {
    if (aIndex >= fSize) {
        throw std::out_of_range("Index out of range");
    }
    Node current = fHead;
    for (size_t i = 0; i < aIndex; ++i) {
        current = current->fNext;
    }
    return current->fData;
}

// Iterator functions
template <typename T>
typename List<T>::Iterator List<T>::begin() const noexcept {
    return Iterator(fHead, fTail);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const noexcept {
    return Iterator(nullptr, fTail);
}

template <typename T>
typename List<T>::Iterator List<T>::rbegin() const noexcept {
    return Iterator(fTail, fHead);
}

template <typename T>
typename List<T>::Iterator List<T>::rend() const noexcept {
    return Iterator(fHead, nullptr);
}

// Explicit instantiation for List<std::string>
template class List<std::string>;
