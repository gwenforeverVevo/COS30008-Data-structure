#ifndef CHARACTER_ITERATOR_H
#define CHARACTER_ITERATOR_H

#include "GameCharacter.h"
#include <vector>

class CharacterIterator
{
private:
    std::vector<GameCharacter> characters;

public:
    // Constructor to initialize with a list of game characters
    CharacterIterator(const std::vector<GameCharacter> &characters);

    // Forward iterator class
    class Iterator
    {
    private:
        std::vector<GameCharacter>::iterator current;

    public:
        // Constructor
        Iterator(std::vector<GameCharacter>::iterator it);

        // Dereference operator
        GameCharacter &operator*() const;

        // Pre-increment operator
        Iterator &operator++();

        // Equality and inequality operators
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
    };

    // Begin and End functions to return iterators
    Iterator begin();
    Iterator end();
};

#endif // CHARACTER_ITERATOR_H
