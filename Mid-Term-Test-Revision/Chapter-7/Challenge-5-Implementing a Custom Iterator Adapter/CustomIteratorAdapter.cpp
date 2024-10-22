#include "CustomIteratorAdapter.h"

using namespace std;

template <typename Iterator>
CustomIteratorAdapter<Iterator>::CustomIteratorAdapter(Iterator iterator) : it(iterator)
{
}
template <typename Iterator>
typename std::iterator_traits<Iterator>::reference CustomIteratorAdapter<Iterator>::operator*() const
{
    return *it;
}

template <typename Iterator>
CustomIteratorAdapter<Iterator> &operator++()
{
    ++it;
    return *this;
}
template <typename Iterator>
CustomIteratorAdapter<Iterator> &operator--()
{
    --it;
    return *this;
}
template <typename Iterator>
bool CustomIteratorAdapter<Iterator>::operator==(const CustomIteratorAdapter &other) const
{
    return it == other.it;
}
template <typename Iterator>
bool CustomIteratorAdapter<Iterator>::operator!=(const CustomIteratorAdapter &other) const
{
    return !(it == other.it);
}