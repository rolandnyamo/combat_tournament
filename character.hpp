// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: May 11, 2019
// .description: implementation file for the character abstract class with [a] dice(s).
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

//.defines a dice and the roll function logic.
struct Dice
{
    int sides;
    int roll()
    {
        srand(time(NULL) + sides);
        return 1 + rand()% sides;
    };
    Dice(int s = 0){sides = s;};//default constructor with 0 sides if not specified
};

class Character
{
protected:
    std::string name;
    std::string type;
    std::string teamName;
    int armor;
    int strength;
    int damage;//damage inflicged by this character
    bool dies;//is true when a character dies

    
public:
    Character();
    virtual int calcDamage(int) = 0;
    virtual int attack(Character *) = 0;
    virtual int defend() = 0;
    virtual int getStrength() = 0;
    virtual bool isDead() = 0;
    virtual void won() = 0;
    virtual void setName(std::string) = 0;
    virtual std::string getName() = 0;
    virtual std::string getType() = 0;
    virtual void recover() = 0;
    virtual void setTeam(std::string) = 0;
    virtual ~Character() = 0;
};
#endif