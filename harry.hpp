#ifndef HARRY_HPP
#define HARRY_HPP

#include "character.hpp"

class Harry: public Character
{
private:
    Dice *attack_dice[2];//pointer to the character's attack dice(s).
    Dice *defense_dice[2];//pointer to the character's defense dice(s).
    int dead;//to keep track of how many times Harry has died
public:
    Harry();
    virtual int calcDamage(int);//calculates the damage inflicted to this character
    virtual int attack(Character *);
    virtual int defend();//defends, then subtracts from the strength
    virtual bool isDead();//returns true when Harry dies
    virtual void won();//to be called when this character won the game
    virtual int getStrength();
    virtual void setName(std::string);
    virtual std::string getName();
    virtual std::string getType();
    virtual void recover();
    virtual void setTeam(std::string);
   ~Harry();
};
#endif