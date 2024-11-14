#pragma once
#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"
#include <utility>
#include <stdexcept>

template <typename T>
class List
{
private:
    using Node = typename DoublyLinkedList<T>::Node;
    Node fHead;   // first element
    Node fTail;   // last element
    size_t fSize; // number of elements

public:
    using Iterator = DoublyLinkedListIterator<T>;

    // Default constructor
    List() noexcept : fHead(nullptr), fTail(nullptr), fSize(0) {}

    // Copy constructor
    List(const List& aOther) : fHead(nullptr), fTail(nullptr), fSize(0) {
        Node nodePosition = aOther.fHead;
        while (nodePosition) {
            push_back(nodePosition->fData);
            nodePosition = nodePosition->fNext;
        }
    }

    // Copy assignment operator
    List& operator=(const List& aOther) {
        if (this != &aOther) {  // Avoid self-assignment
            List temp(aOther);   // Copy constructor creates a temp copy
            swap(temp);          // Swap contents with temp
        }
        return *this;
    }

    // Move constructor
    List(List&& aOther) noexcept 
        : fHead(std::move(aOther.fHead)), fTail(std::move(aOther.fTail)), fSize(aOther.fSize) 
    {
        aOther.fHead = nullptr;
        aOther.fTail = nullptr;
        aOther.fSize = 0;
    }

    // Move assignment operator
    List& operator=(List&& aOther) noexcept {
        if (this != &aOther) {  // Avoid self-assignment
            // Release any resources currently held by this
            fHead.reset();
            fTail.reset();
            fSize = 0;

            // Transfer ownership of resources from aOther to this
            fHead = std::move(aOther.fHead);
            fTail = std::move(aOther.fTail);
            fSize = aOther.fSize;

            // Reset aOther to an empty state
            aOther.fHead = nullptr;
            aOther.fTail = nullptr;
            aOther.fSize = 0;
        }
        return *this;
    }

    // Swap function (using std::swap)
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
    template <typename U>
    void push_front(U&& aData) {
        Node newPushFront = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));
        if (fHead == nullptr) {
            fHead = fTail = newPushFront;
        } else {
            newPushFront->fNext = fHead;
            fHead->fPrevious = newPushFront;
            fHead = newPushFront;
        }
        ++fSize;
    }

    // Add element at back
    template <typename U>
    void push_back(U&& aData) {
        Node newPushBack = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));
        if (fTail == nullptr) {
            fHead = fTail = newPushBack;
        } else {
            newPushBack->fPrevious = fTail;
            fTail->fNext = newPushBack;
            fTail = newPushBack;
        }
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
                    } else {
                        fTail = nullptr;
                    }
                } else if (current == fTail) {
                    fTail = current->fPrevious.lock();
                    if (fTail) {
                        fTail->fNext = nullptr;
                    } else {
                        fHead = nullptr;
                    }
                } else {
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
        if (aIndex >= fSize) {
            throw std::out_of_range("Index out of range");
        }
        Node newNode = fHead;
        for (size_t i = 0; i < aIndex; ++i) {
            newNode = newNode->fNext;
        }
        return newNode->fData;
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
