#include "GameCharacter.h"
#include <iostream>

using namespace std;

// Constructor to initialize game character
GameCharacter::GameCharacter(const std::string &name, int health, int strength)
    : name(name), health(health), strength(strength) {}

// Get the character's name
const std::string &GameCharacter::getName() const
{
    return name;
}

// Get the character's health
int GameCharacter::getHealth() const
{
    return health;
}

// Get the character's strength
int GameCharacter::getStrength() const
{
    return strength;
}

// Modify character's health by taking damage
void GameCharacter::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;  // Ensure health doesn't go below zero
    }
}

// Display character information
void GameCharacter::display() const
{
    cout << "Name: " << name << ", Health: " << health << ", Strength: " << strength << endl;
}
