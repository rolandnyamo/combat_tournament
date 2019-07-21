// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: May 16th, 2019
// .description: implementation file that defines a list  lineup.

#include "lineup.hpp"
#include <iostream>
#include <string>
#include <cstring>

// .description: default contructor, initializes head to null, name to empty, score to 0.
Lineup::Lineup()
{
    name = "";
    score = 0;
    head = NULL;
}
// .description: checks if the lineup is empty, if so returns true, otherwise return false.
bool Lineup::isEmpty()
{
    if (!head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// .description: adds an int to the back of the lineup
void Lineup::addBack(Character *v)
{
    

    if (isEmpty())//if it's an empty lineup
    {
        CharacterNode *t = new CharacterNode(v);//temp node for swapping

        head = t;
        head->next = head;
        head->prev = head;
    }
    else if (head == head->prev)//if there's only one item in the lineup
    {
        CharacterNode *t = new CharacterNode(v);//temp node for swapping

        head->prev = t;
        t->next = head;
        t->prev = head;
        head->next = t;
    }
    else//there's more than one item in the lineup
    {
        CharacterNode *t = new CharacterNode(v, head->prev, head);//temp node for swapping

        head->prev->next = t;
        head->prev = t;
    }
}

// .description: Prints the front lineup value.
CharacterNode * Lineup::getFront()
{
    std::cout << "\n";
    if (isEmpty())
    {
        std::cout << "This list seems to be empty!\n";
        return head;
    }

    return head;
}

// .description: deletes the item at the front of the lineup.
void Lineup::removeFront()
{
    if (!isEmpty())
    {
        if (head == head->prev)//if there's only 1 item in the lineup
        {
            delete head;
            head = NULL;
        }
        else
        {
            CharacterNode *t = head->next;
            head->prev->next = t; //point t to next position of the last node to keep it circular
            t->prev = head->prev;
            delete head;
            head = NULL;
            head = t; //make t the head
        }
    }
    else
    {
        std::cout << "\nThis lineup seems to be empty!\n";
    }
}

// .description: prints a lineup from first to last item.
void Lineup::printLineup()
{
    std::cout << "\n";
    std::cout << "\n";
    std::cout << name << " lineup:\n";
    CharacterNode *temp;
    if (!isEmpty())
    {
        temp = head;//start from the first lineup item.
        std::cout << "\nName: " << temp->xter->getName() <<
         "      Type: " << temp->xter->getType() << 
         "      Strength: " << temp->xter->getStrength();

        while (temp != head->prev)
        {
            temp = temp->next;
            std::cout << "\n";  
            std::cout << "Name: " << temp->xter->getName() <<
            "      Type: " << temp->xter->getType() << 
            "       Strength: " << temp->xter->getStrength();
        }
        std::cout << "\n";                
    }
    else
    {
        std::cout << "\nThis lineup seems to be empty!\n";
    }
}

//. sets the lineup's name
void Lineup::setName(std::string lName)
{
    name = lName;
}

//. returns the team's name as string
std::string Lineup::getName()
{
    return name;
}

//. returns the linup's score
int Lineup::getScore()
{
    return score;
}

//. adds to the lineup's score

void Lineup::addToScore(int s)
{
    score += s;
}
//.destructor
Lineup::~Lineup()
{
    CharacterNode *temp;

    if (!isEmpty())
    {
        head->prev->next = NULL;//cut the circle so you know when you're at the end
    }

    while (!(isEmpty()))
    {
        temp = head->next;

        if (head->xter != NULL)
        {
            delete head->xter;
            head->xter = NULL;
        }
        
        delete head;
        head = NULL;
        head = temp;
    }
    temp = NULL;
}