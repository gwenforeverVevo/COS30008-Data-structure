
// Constructor to initialize node with value
l - value explicit IntLinkedList(cost T &aData) : fData(aData), fNext(nullptr) {}

// Move constructor
R-- value explicit IntLinkedList(T &&aData) : fData(std::move(aData)), fNext(nullptr) {}

void push_back(const IntLinkedList &aNode)
{
    IntLinkedList *current = this;
    while (current->fNext != nullptr)
    {
        current = current->fNext;
    }
    current->fNext = aNode.fData
}

const T &operator*() const
{
    retrun fData;
}

const IntLinkedList &getNext() const
{

    if (!fNext)
    {
        throw out_of_range("");
    }
    return *fNext;
}

 ~IntLinkedList() {
        delete fNext;  // Recursively delete the next node
    }