using Iterator = MyIterator<T>;

ListIterator<T>(const ListNode *aList) : fList(aList), fIndex(aIndex);
{
}

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
    MyIterator temp = *this;
    ++fIndex;
    return temp;

}

bool operator==(const Iterator& aItr) const 
{
    return (fList ==aItr.fList);
}
bool operator!=(const Iterator& aItr) const 
{
    return !(fList==aItr.fList);
}

const Iterator begin(){
   return ListIterator(aList); 
}
const Iterator end(){
   return ListIterator(nullptr); 
}