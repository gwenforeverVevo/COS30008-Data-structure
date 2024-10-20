#include <iostream>
#include <GameCharacter.h>
#include <string>

using namespace std;

GameCharacter::GameCharacter(const string& aId, const string& aName, int aStrength, int aLive) : fId(aId), fName(aName), fStrength(aStrength) , fLives(aLives)
{

}

int GameCharacter::getStrength() const
{
    return fStrength;
}

int GameCharacter::checkLives() const
{
    return fLives;
}
