#include <iostream>
#include <CharacterIterator.h>
#include <string>

using namespace std;

ChacracterIterator::CharacterIterator(GameCharacter* aCharacter, int aLength,int aStart) : fCharacter(aCharacter), fLength(aLength), fStart(aStart)
{

}

const GameCharacter* CharacterIterator::operator*() const

{
    return fCharacter[aIndex];
}

CharacterIterator& CharacterIterator::operator++()
{
    ++aIndex;
    return *this;
}

CharacterIterator& CharacterIterator::operator++(int)
{
    ChracterIterator temp = *this;
    aIndex++;
    return temp;
}

bool CharacterIterator::operator==(const CharacterIterator& other) const
{
    return (aIndex == other.aIndex) && (fCharacter == other.fCharacter);
}

bool CharacterIterator::operator!=(const CharacterIterator& other) const
{
    // Inequality means either the indices or the character array are different
    return !(*this == other);  // Reuse the equality operator
}

CharacterIterator CharacterIterator::begin() const
{
    return CharacterIterator(fCharacter, fLength, fStart);
}

CharacterIterator CharacterIterator::end() const
{
    return CharacterIterator(fCharacter, fLength, fLength);
}

