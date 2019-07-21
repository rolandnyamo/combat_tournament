#include "medusa.hpp"

Medusa::Medusa()
{
    //initialize the attack dice with 10 sides

    for (int i = 0; i < 2; i++)
    {
        attack_dice[i] = new Dice(10);
    }

    //set the defense dice sides
    defense_dice = new Dice(6);

    //set armor and strength
    armor = 3;
    strength = 8;
    dies = false;
    type = "Medusa";
    name = "Medusa";
}

//. description: Medusa's attack function.
//. .other notes: this also applies glare randomly
//. argument: another charater
//. return: result of the attack
int Medusa::attack(Character *c)
{
    if (!dies)
    {
        int attack_pts = 0; int damage = 0;

        if (c->getType() == "Vampire")
        {
            srand(time(NULL) + strength + armor);
            int ran = 1 + rand() % 2;

            if (ran == 1)
            {
                std::cout << "\n" << c->getName() << " has charmed " <<
                getName() << "\n";
                std::cout << "\n"<< getName() << " will not attack " <<
                c->getName() << ".\n";

                return 0;
            }
            else if (ran == 2)
            {
                std::cout << "\n"<< getName() << " is attacking " <<
                //adapted from https://gist.github.com/bolry/ca4f90a93ff1066a10b44d9947fa8312
                c->getName() << "\n";

                for (int i = 0; i < 2; i++)
                {
                    attack_pts += attack_dice[i]->roll();
                }
                std::cout << "Attack points: " << attack_pts;

                if (attack_pts == 12)
                {
                    std::cout << "\n"<< getName() << " has applied glare on " << c->getName() << std::endl;

                    c->calcDamage(c->getStrength());//kill the attacked character.

                    return 0;
                }
                else
                {
                    damage = attack_pts - c->defend();
                    if (damage < 0)//damage floor is 0
                    {
                        damage = 0;
                    }
                    

                    std::cout << "\nTotal inflicted damage is " << damage;
                    //calculate this attack's damage on the attacked character
                    c->calcDamage(damage);

                    std::cout << "\n"
                            << c->getName() << "'s new strength is " << c->getStrength() << std::endl;

                    return damage;
                }
            }
        }
        else
        {
            std::cout << "\n"<< getName() << " is attacking " << c->getName() << "\n";

            for (int i = 0; i < 2; i++)
            {
                attack_pts += attack_dice[i]->roll();
            }
            std::cout << "Attack points: " << attack_pts;

            if (attack_pts == 12)
            {
                std::cout << "\n"<< getName() << " has applied glare on " << c->getName() << std::endl;

                c->calcDamage(c->getStrength());//kill the opponent.

                return 0;
            }
            else
            {
                damage = attack_pts - c->defend();
                
                if (damage < 0)//damage floor is 0
                {
                    damage = 0;
                }
                std::cout << "\nTotal inflicted damage is " << damage;
                //calculate this attack's damage on the attacked character
                c->calcDamage(damage);

                std::cout << "\n"
                        << c->getName() << "'s new strength is " << c->getStrength() << std::endl;

                return damage;
            }
        }
    }
    else
    {
        std::cout << "\n"<< name << " is dead, they cannot attack\n";

        return 0;
    }
    
    return -1;
}

//. description: Medusa's defend class
//. argument: none
//. return: returns the dice roll and armor
int Medusa::defend()
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
int Medusa::calcDamage(int d)
{
    strength -= d;

    if (strength <= 0)
    {
        dies = true;
        strength = 0;
        std::cout << "\n" << getName() << " has died +_+\n";
    }

    return strength;
}

//. description: calculates damaged caused to
//. this character after an attack
//. argument: none
//. return: remaining strength points
int Medusa::getStrength()
{
    return strength;
}
//. description: returns true is the character is dead
//. argument: none
bool Medusa::isDead()
{
    return dies;
}
//. description: prints that the character has won with xx points
//. argument: none
void Medusa::won()
{
    std::cout << "\n" << getName() << " won with " << getStrength() << " remaining strength points.\n";
}
//. description: sets the character's name to a specified string
//. argument: string for name
void Medusa::setName(std::string n)
{
    name = n;
}
//. description: returns the character's name
//. argument: none
//. return type: string
std::string Medusa::getName()
{
    return teamName + " " + name;
}
//. description: returns the character's type
//. argument: none
//. return type: string
std::string Medusa::getType()
{
    return type;
}
//. description: adds half the strength required to be at full strength 
//.              after a character wins a fight
//. argument: none
//. return type: string
void Medusa::recover()
{
    int c_strength = getStrength();//current character strength

    strength += (8 - c_strength)/2;
}
//. sets medusa's team name
void Medusa::setTeam(std::string t)
{
    teamName = t;
}
//.destructor
Medusa::~Medusa()
{
    for (int i = 0; i < 2; i++)
    {
        delete attack_dice[i];
        attack_dice[i] = NULL;
    }

    delete defense_dice;
    defense_dice = NULL;
}