#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string>

class GameCharacter
{
private:
    std::string name;
    int health;
    int strength;

public:
    // Constructor
    GameCharacter(const std::string &name, int health, int strength);

    // Accessors
    const std::string &getName() const;
    int getHealth() const;
    int getStrength() const;

    // Modify character's health (take damage)
    void takeDamage(int damage);

    // Display character information
    void display() const;
};

#endif // GAME_CHARACTER_H
