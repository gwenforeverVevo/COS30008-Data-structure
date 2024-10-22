#include "CharacterIterator.h"

using namespace std;

// Constructor to initialize the iterator with characters
CharacterIterator::CharacterIterator(const vector<GameCharacter> &characters)
    : characters(characters) {}

// Begin function returning an iterator pointing to the beginning of the character list
CharacterIterator::Iterator CharacterIterator::begin()
{
    return Iterator(characters.begin());
}

// End function returning an iterator pointing to the end of the character list
CharacterIterator::Iterator CharacterIterator::end()
{
    return Iterator(characters.end());
}

// Iterator constructor
CharacterIterator::Iterator::Iterator(vector<GameCharacter>::iterator it) : current(it) {}

// Dereference operator to access the current character
GameCharacter &CharacterIterator::Iterator::operator*() const
{
    return *current;
}

// Pre-increment operator to move to the next character
CharacterIterator::Iterator &CharacterIterator::Iterator::operator++()
{
    ++current;
    return *this;
}

// Equality operator to compare two iterators
bool CharacterIterator::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

// Inequality operator to compare two iterators
bool CharacterIterator::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}
