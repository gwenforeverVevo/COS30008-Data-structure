#pragma once
#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"
#include <utility>

template<typename T>
class List
{
private:
    using Node = typename DoublyLinkedList<T>::Node;
    Node fHead; // first element
    Node fTail; // last element
    size_t fSize; // number of elements

public:
    using Iterator = DoublyLinkedListIterator<T>;

    List() noexcept : fHead(nullptr), fTail(nullptr), fSize(0) {} // default constructor

    // Copy constructor
    List(const List& aOther) : fHead(nullptr), fTail(nullptr), fSize(0) {
        Node current = aOther.fHead;
        while (current) {
            push_back(current->fData);
            current = current->fNext;
        }
    }

    // Copy assignment operator
    List& operator=(const List& aOther) {
        if (this != &aOther) {
            List temp(aOther);
            swap(temp);
        }
        return *this;
    }

    // Move constructor
    List(List&& aOther) noexcept : fHead(std::move(aOther.fHead)), fTail(std::move(aOther.fTail)), fSize(aOther.fSize) {
        aOther.fHead = nullptr;
        aOther.fTail = nullptr;
        aOther.fSize = 0;
    }

    // Move assignment operator
    List& operator=(List&& aOther) noexcept {
        if (this != &aOther) {
            // Transfer ownership of the elements
            fHead = std::move(aOther.fHead);
            fTail = std::move(aOther.fTail);
            fSize = aOther.fSize;
            // Reset aOther
            aOther.fHead = nullptr;
            aOther.fTail = nullptr;
            aOther.fSize = 0;
        }
        return *this;
    }

    // Swap elements
    void swap(List& aOther) noexcept {
        std::swap(fHead, aOther.fHead);
        std::swap(fTail, aOther.fTail);
        std::swap(fSize, aOther.fSize);
    }

    // List size
    size_t size() const noexcept {
        return fSize;
    }

    // Add element at front
    template<typename U>
    void push_front(U&& aData) {
        Node newNode = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));
        newNode->fNext = fHead;
        if (fHead) {
            fHead->fPrevious = newNode;
        }
        else {
            fTail = newNode; // list was empty
        }
        fHead = newNode;
        ++fSize;
    }

    // Add element at back
    template<typename U>
    void push_back(U&& aData) {
        Node newNode = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));
        newNode->fPrevious = fTail;
        if (fTail) {
            fTail->fNext = newNode;
        }
        else {
            fHead = newNode; // list was empty
        }
        fTail = newNode;
        ++fSize;
    }

    // Remove element
    void remove(const T& aElement) noexcept {
        Node current = fHead;
        while (current) {
            if (current->fData == aElement) {
                if (current == fHead) {
                    fHead = current->fNext;
                    if (fHead) {
                        fHead->fPrevious.reset();
                    }
                    else {
                        fTail = nullptr; // list is now empty
                    }
                }
                else if (current == fTail) {
                    fTail = current->fPrevious.lock();
                    if (fTail) {
                        fTail->fNext = nullptr;
                    }
                    else {
                        fHead = nullptr; // list is now empty
                    }
                }
                else {
                    current->fPrevious.lock()->fNext = current->fNext;
                    current->fNext->fPrevious = current->fPrevious;
                }
                --fSize;
                current->isolate();
                return;
            }
            current = current->fNext;
        }
    }

    // List indexer
    const T& operator[](size_t aIndex) const {
        Node current = fHead;
        for (size_t i = 0; i < aIndex; ++i) {
            current = current->fNext;
        }
        return current->fData;
    }

    // Iterator interface
    Iterator begin() const noexcept {
        return Iterator(fHead, fTail).begin();
    }

    Iterator end() const noexcept {
        return Iterator(fHead, fTail).end();
    }

    Iterator rbegin() const noexcept {
        return Iterator(fHead, fTail).rbegin();
    }

    Iterator rend() const noexcept {
        return Iterator(fHead, fTail).rend();
    }
};
