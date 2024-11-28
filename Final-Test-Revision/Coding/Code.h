template <class T>
class IntiListList
{
private:
    T fData;
    IntiListList *fNext;

public:
    explicit IntiListList(const T &aData) : fData(aData), fNext(nullptr)
    {
    }
    explicit IntiListList(const T &&aData) : fData(std::move(aData)), fNext(nullptr)
    {
    }

    void push_back(const IntiListList &aNode)
    {
        IntiListList *current = this;
        while (current->fNext != nullptr)
        {
            current = current->fNext;
        }
        current->fNext = aNode;
    }
    const T &operator*() const
    {
        return this->fData;
    }

    const IntiListList &getNext() const
    {
        return this->fNext;
    }
}

template <class T>
class MyIterator
{
private:
    using ListNode = IntiListList<T>;
    const ListNode *fList;
    const ListNode *fIndex;

public:
    using Iterator = MyIterator;

    const T &operator*() const
    {
        return fIndex;
    }

    Iterator operator++()
    {
        ++fIndex;
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator *temp = this;

        ++fIndex;

        return *temp;
    }

    bool operator==(const Iterator &aItr) const
    {
        return (fList == aItr.fList && fIndex == aItr.fIndex);
    }

    bool operator!=(const Iterator &aItr) const
    {
        return !(fList == aItr.fList && fIndex == aItr.fIndex);
    }
}