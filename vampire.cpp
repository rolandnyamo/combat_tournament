#include "vampire.hpp"
#include <typeinfo>

Vampire::Vampire()
{
    //initialize the attack dice with 12 sides
    attack_dice = new Dice(12);
    
    //set the defense dice sides
    defense_dice = new Dice(6);

    //set armor and strength
    armor = 1;
    strength = 18;
    dies = false;
    type = "Vampire";
    name = "Vampire";
}

//. description: Vampire's attack class
//. argument: another charater
//. return: result of the attack
int Vampire::attack(Character *c)
{
    if (!dies)
    {
        int attack_pts = 0; int damage = 0;

        std::cout << "\n"<< getName() << " is attacking " <<
        c->getName()<< "\n";

        attack_pts += attack_dice->roll();

        std::cout << "Attack points: " << attack_pts;
        
        damage = attack_pts - c->defend();
        if (damage < 0)
        {
            damage = 0;
        }
        
        std::cout << "\nTotal inflicted damage is " << damage;
        //calculate this attack's damage on the attacked character
        c->calcDamage(damage);
    
        std::cout << "\n" << c->getName() << 
        "'s new strength is " << c->getStrength() << std::endl;

        return damage;
    }
    else
    {
        std::cout << "\n"<< getName() << " is dead, so they cannot attack.\n";

        return 0;
    }
    
    return -1;
}

//. description: Vampire's defend class
//. argument: none
//. return: returns the dice roll and armor
int Vampire::defend()
{
    int defend_roll = defense_dice->roll();

    std::cout << "\n"<< getName() << " defence dice roll: " << defend_roll <<
    " with an armor of " << armor;
    return defend_roll + armor;
}

//. description: calculates damaged caused to
//. this character after an attack
//. argument: damage points from attack
//. return: remaining strength points
int Vampire::calcDamage(int d)
{
    strength -= d;

    if (strength <= 0)
    {
        dies = true;
        strength = 0;
        std::cout << "\n"<< getName() << " has died +_+\n";
    }

    return strength;
}

//. description: calculates damaged caused to
//. this character after an attack
//. argument: none
//. return: remaining strength points
int Vampire::getStrength()
{
    return strength;
}
//. description: returns true is the character is dead
//. argument: none
bool Vampire::isDead()
{
    return dies;
}
//. description: prints that the character has won with xx points
//. argument: none
void Vampire::won()
{
    std::cout << "\n"<< getName() << " won with " << getStrength() << " remaining strength points.\n";
}

//. description: sets the character's name to a specified string
//. argument: string for name
void Vampire::setName(std::string n)
{
    name = n;
}
//. description: returns the character's name
//. argument: none
//. return type: string
std::string Vampire::getName()
{
    return teamName + " " + name;
}
//. description: returns the character's type
//. argument: none
//. return type: string
std::string Vampire::getType()
{
    return type;
}
//. description: adds half the strength required to be at full strength 
//.              after a character wins a fight
//. argument: none
//. return type: string
void Vampire::recover()
{
    int c_strength = getStrength();//current character strength

    strength += (18 - c_strength)/2;
}
//. sets vammpire's team name
void Vampire::setTeam(std::string t)
{
    teamName = t;
}
//.destructor
Vampire::~Vampire()
{
    delete attack_dice;
    attack_dice = NULL;
    delete defense_dice;
    defense_dice = NULL;
}