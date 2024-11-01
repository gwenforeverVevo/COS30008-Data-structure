#include "Stack.h"
#include <iostream>

template <typename T>
Stack<T>::Stack()
    : fElements(nullptr), fStackPointer(0), fCurrentSize(1)
{
    fElements = new T[fCurrentSize];
}

template <typename T>
void Stack<T>::resize(size_t aNewSize)
{
    T *newElements = new T[aNewSize];
    for (size_t i = 0; i < fStackPointer; ++i)
        newElements[i] = fElements[i];
    delete[] fElements;
    fElements = newElements;
    fCurrentSize = aNewSize;
}

template <typename T>
void Stack<T>::ensure_capacity()
{
    if (fStackPointer >= fCurrentSize)
        resize(fCurrentSize * 2);
}

template <typename T>
void Stack<T>::adjust_capacity()
{
    if (fStackPointer < fCurrentSize / 4 && fCurrentSize > 1)
        resize(fCurrentSize / 2);
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] fElements;
}


