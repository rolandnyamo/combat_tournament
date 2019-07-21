// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: May 11, 2019
// .description: implementation file for the character abstract class.

#include "character.hpp"
#include <string>

//.default constructor, does nothing side it's an abstract class.
Character::Character()
{
    armor = 0;
    strength = 0;
}

//.destructor
Character::~Character()
{
    
}