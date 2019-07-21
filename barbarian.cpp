#include "barbarian.hpp"

Barbarian::Barbarian()
{
    //initialize the attack dice with 6 sides

    for (int i = 0; i < 2; i++)
    {
        attack_dice[i] = new Dice(6);
    }
    
    //set the defense dice sides
    for (int i = 0; i < 2; i++)
    {
        defense_dice[i] = new Dice(6);
    }

    //set armor and strength
    armor = 0;
    strength = 12;
    dies = false;
    type = "Barbarian";
    name = "Barbarian";
}

//. description: Barbarian's attack class
//. argument: another charater
//. return: result of the attack
int Barbarian::attack(Character *c)
{
    if (!dies)
    {
        int attack_pts = 0; int damage = 0;

        if (c->getType() == "Vampire")
        {
            srand(time(NULL) + strength + armor);
            int ran = 1 + rand()% 2;
            
            if (ran == 1)
            {
                std::cout << "\n" << c->getName() << " has charmed " <<
                getName() << "\n";
                std::cout << "\n" << getName() << " will not attack Vampire.\n";

                return 0;
            }
            else if (ran == 2)
            {
                std::cout << "\n" << getName() << " is attacking " <<
                c->getName() << "\n";

                for (int i = 0; i < 2; i++)
                {
                    attack_pts += attack_dice[i]->roll();
                }

                attack_pts = 1 + rand()% attack_pts;

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
        }
        else
        {
            std::cout << "\n" << getName() << " is attacking " <<
            c->getName() << "\n";

            for (int i = 0; i < 2; i++)
            {
                attack_pts += attack_dice[i]->roll();
            }
            attack_pts = 1 + rand()% attack_pts;

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
    }
    else
    {
        std::cout << "\n" << getName() << " is dead, they cannot attack.\n";

        return 0;
    }
    
    return -1;
}

//. description: Barbarian's defend class
//. argument: none
//. return: returns the dice roll and armor
int Barbarian::defend()
{
    int defend_roll = 0;

    for (int i = 0; i < 2; i++)
    {
        defend_roll += defense_dice[i]->roll();
    }

    defend_roll = 1 + rand()% 2;

    std::cout << "\n" << name << " defence dice roll: " << defend_roll <<
    " with an armor of " << armor;
    return defend_roll + armor;
}
//. description: calculates damaged caused to
//. this character after an attack
//. argument: damage points from attack
//. return: remaining strength points
int Barbarian::calcDamage(int d)
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
int Barbarian::getStrength()
{
    return strength;
}
//. description: returns true is the character is dead
//. argument: none
bool Barbarian::isDead()
{
    return dies;
}
//. description: prints that the character has won with xx points
//. argument: none
void Barbarian::won()
{
    std::cout << "\n" << getName() << " won with " << getStrength() << " remaining strength points.\n";
}
//. description: sets the character's name to a specified string
//. argument: string for name
void Barbarian::setName(std::string n)
{
    name = n;
}
//. description: returns the character's name
//. argument: none
//. return type: string
std::string Barbarian::getName()
{
    return teamName + " " + name;
}
//. description: returns the character's type
//. argument: none
//. return type: string
std::string Barbarian::getType()
{
    return type;
}
//. description: adds half the strength required to be at full strength 
//.              after a character wins a fight
//. argument: none
//. return type: string
void Barbarian::recover()
{
    int c_strength = getStrength();//current character strength

    strength += (12 - c_strength)/2;
}

//. sets barbarian's team name
void Barbarian::setTeam(std::string t)
{
    teamName = t;
}
//.destructor
Barbarian::~Barbarian()
{
    for (int i = 0; i < 2; i++)
    {
        delete attack_dice[i];
        attack_dice[i] = NULL;
    }

    for (int i = 0; i < 2; i++)
    {
        delete defense_dice[i];
        defense_dice[i] = NULL;
    }
}