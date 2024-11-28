template <class T>
struct snglyLinkedList
{
    T fData;
    SinglelyLinkedList *fNext;
    SinglelyLinkedList(const T &aData, snglyLinkedList<T> *aNext = nullptr) : fData(aData), fNext(aNext)
    {
    }
}

snglyLinkedList<T> *start = nullptr;
//(a)
template <class T>
void snglyLinkedList<T>::addToEnd(snglyLinkedList<int> **list, int value)
{
    snglyLinkedList < int *temp = new snglyLinkedList < int(value);
    if (*list == nullptr)
    {
        *list = temp;
        return;
    }
    Node *current = list;
    while (current->fNext != nullptr)
    {

        current = current->fNext;
    }
    current->fNext = temp;
}

template <class T>
void snglyLinkedList<T>::addToEnd(snglyLinkedList<int> *&list, int value)
{
    ` Node<T> *temp = new Node<T>(value);

    // If the list is empty, set the new node as the head
    if (list->start == nullptr)
    {
        list->start = temp;
        return;
    }

    // Traverse to the last node
    Node<T> *current = list->start;
    while (current->fNext != nullptr)
    {
        current = current->fNext;
    }

    // Link the last node to the new node
    current->fNext = temp;
}

//(b)
template <class T>
void snglyLinkedList<T>::addToFront(snglyLinkedList<int> **list, int value)
{

    snglyLinkedList<int> *temp = new snglyLinkedList<int>(value);
    if (*list == nullptr)
    {
        start = temp;
    }
    else
    {
        temp->fNext = *list;
        *list = temp;
    }
}

void addToFront(snglyLinkedList<T> *&list, T value)
{

    snglyLinkedList<int> *temp = new snglyLinkedList<int>(value);
    if (list->start == nullptr)
    {
        list->start = temp;
    }
    else
    {
        temp->fNext = list;
        list = temp
    }
}

//(C)
void deleteFirst(snglyLinkedList<int> **list)
{

    if (*list == nullptr)
    {
        return;
    }

    snglyLinkedList<int> *temp = *list;
    *list = *list->fNext;
    delete temp;
}

void deleteFirst(snglyLinkedList<int> *&list)
{

    if (list == nullptr)
    {
        return;
    }

    snglyLinkedList<int> *temp = list;
    list = list->fNext;
    delete temp;
}

//(D)

void deleteLast(snglyLinkedList<int> **list)
{
    if (*list == nullptr)
    {
        return; // Empty list, nothing to delete
    }
    snglyLinkedList<int> *temp = *list;
    while (temp->fNext != nullptr && temp->fNext->fNext != nullptr)
    {
        temp = temp->fNext;
    }
    snglyLinkedList<int> *lastNode = temp->fNext;
    temp->fNext = nullptr;

    delete lastNode;
}


void deleteLast(snglyLinkedList<int> *&list)
{
    if (list == nullptr)
    {
        return; // Empty list, nothing to delete
    }
    snglyLinkedList<int> *temp = list;
    while (temp->fNext != nullptr && temp->fNext->fNext != nullptr)
    {
        temp = temp->fNext;
    }
    snglyLinkedList<int> *lastNode = temp->fNext;
    temp->fNext = nullptr;

    delete lastNode;
}