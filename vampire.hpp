#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire: public Character
{
private:
    Dice *attack_dice;//pointer to the character's attack dice(s).
    Dice *defense_dice;//pointer to the character's defense dice(s).
public:
    Vampire();
    virtual int calcDamage(int);//calculates the damage inflicted to this character
    virtual int attack(Character *);
    virtual int defend();//defends, then subtracts from the strength
    virtual bool isDead();//returns true when Vampire dies
    virtual void won();//to be called when this character won the game
    virtual int getStrength();
    virtual void setName(std::string);
    virtual std::string getName();
    virtual std::string getType();
    virtual void recover();
    virtual void setTeam(std::string);
   ~Vampire();
};
#endif