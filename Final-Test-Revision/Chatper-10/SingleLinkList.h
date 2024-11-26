

SinglyLinkedListIterator(const ListNode &aList) : fList(aList), fIndex(aList)
{
}

const T &operator*() const
{

    return fList->fData;
}

Iterator &operator++()
{
    fIndex = fIndex->fNext;
    return *this;
}

Iterator operator++(int)
{
    Iterator old = *this;
    ++(*this);
    return old;
}

bool operator==(const Iterator &aRHS) const
{
    return fList == aRHSfList &&
           fIndex == aRHS.Index;
}

bool operator!=(const Iterator &aRHS) const
{
    return !(fList == aRHSfList ||
             fIndex == aRHS.Index);
}

Iterator begin()
{
    Iterator iter = *this;
    iter.fIndex = iter.fList;
    return iter;
}

Iterator end()
{
    Iterator iter = *this;
    iter.fIndex = nullptr;
    return iter;
}