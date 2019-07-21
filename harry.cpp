#include "harry.hpp"
#include "vampire.hpp"

Harry::Harry()
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
    strength = 10;//starting strenght
    dead = 0;
    dies = false;
    type = "Harry Potter";
    name = "Harry";
}

//. description: Harry's attack class
//. argument: another charater
//. return: result of the attack
int Harry::attack(Character *c)
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
                getName() << ".\n";
                std::cout << "\n" << getName() << " will not attack " << 
                c->getName() << ".\n";

                return 0;
            }
            else if (ran == 2)
            {
                std::cout << "\n"<< getName() << " is attacking " <<
                c->getName()<< "\n";

                for (int i = 0; i < 2; i++)
                {
                    attack_pts += attack_dice[i]->roll();
                }
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
            c->getName()<< "\n";

            for (int i = 0; i < 2; i++)
            {
                attack_pts += attack_dice[i]->roll();
            }
            
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
        std::cout << "\n" << name << " is dead, so he cannot attack.\n";

        return 0;
    }
    
    return -1;
}

//. description: Harry's defend class
//. argument: none
//. return: returns the dice roll and armor
int Harry::defend()
{
    int defend_roll = 0;
    srand(time(NULL) + strength);
    
    for (int i = 0; i < 2; i++)
    {
        defend_roll += defense_dice[i]->roll();
    }

    defend_roll = 1 + rand()% 4;

    std::cout << "\n"<< getName() << " defence dice roll: " << defend_roll <<
    " with an armor of " << armor;
    return defend_roll + armor;
}

//. description: calculates damaged caused to
//. this character after an attack
//. argument: damage points from attack
//. return: remaining strength points
int Harry::calcDamage(int d)
{
    strength -= d;

    if (strength <= 0)
    {
        dies = true;
        dead ++;
        strength = 0;
        std::cout << "\n" << getName() << " has died +_+\n";
    }

    //If Harry has died once, bring him back
    if (dead == 1)
    {
        strength = 20;
        std::cout << "..but he has revived with " << strength <<
        " points of strength.\n";
        dies = false;
        dead = 2;//so that you never bring him back again.
    }
    
    return strength;
}

//. description: calculates damaged caused to
//. this character after an attack
//. argument: none
//. return: remaining strength points
int Harry::getStrength()
{
    return strength;
}
//. description: returns true is the character is dead
//. argument: none
bool Harry::isDead()
{
    return dies;
}
//. description: prints that the character has won with xx points
//. argument: none
void Harry::won()
{
    std::cout << "\n"<< getName() << " won with " << getStrength() << " remaining strength points.\n";
}
//. description: sets the character's name to a specified string
//. argument: string for name
void Harry::setName(std::string n)
{
    name = n;
}
//. description: returns the character's name
//. argument: none
//. return type: string
std::string Harry::getName()
{
    return teamName + " " + name;
}
//. description: returns the character's type
//. argument: none
//. return type: string
std::string Harry::getType()
{
    return type;
}
//. description: adds half the strength required to be at full strength 
//.              after a character wins a fight
//. argument: none
//. return type: string
void Harry::recover()
{
    int c_strength = getStrength();//current character strength
    if (c_strength > 10)//meaning harry is in his second life and may have more than 10 strength pts
    {
        strength += (20 - c_strength)/2;
    }
    else
    {
        strength += (10 - c_strength)/2;
    }  
}

//. sets Harry's team name
void Harry::setTeam(std::string t)
{
    teamName = t;
}
//.destructor
Harry::~Harry()
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