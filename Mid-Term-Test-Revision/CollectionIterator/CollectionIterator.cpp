#include "CollectionIterator.h"

using namespace std;

CollectionIterator::CollectionIterator(const std::vector<int> &collection) : fCollection(collection) {}

Iterator CollectionIterator::begin()
{
    return Iterator(fCollection.begin());
}
Iterator CollectionIterator::end()
{
    return Iterator(fCollection.end());
}