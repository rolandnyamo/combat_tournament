#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"

class Bluemen: public Character
{
private:
    Dice *attack_dice[2];//pointer to the character's attack dice(s).
    Dice *defense_dice[3];//pointer to the character's defense dice(s).
    int total_damage;//keeps track of the damage
    int die_change;//keeps track of the number of times dice number has changed
public:
    Bluemen();
    virtual int calcDamage(int);//calculates the damage inflicted to this character
    virtual int attack(Character *);
    virtual int defend();//defends, then subtracts from the strength
    virtual bool isDead();//returns true when Bluemen dies
    virtual void won();//to be called when this character won the game
    virtual int getStrength();
    virtual void setName(std::string);
    virtual std::string getName();
    virtual std::string getType();
    virtual void recover();
    virtual void setTeam(std::string);
   ~Bluemen();
};
#endif