// .author: Roland Nyamoga (nyamogar@oregonstate.edu)
// .date: May 16th, 2019
// .description: header file that defines a node linked list.

#ifndef LINEUP_HPP
#define LINEUP_HPP
#include <iostream>
#include "character.hpp"

//. description: this defines a node of int type value.
struct CharacterNode 
{
    Character *xter;
    CharacterNode  *prev;
    CharacterNode  *next;
    CharacterNode  (Character *x = NULL, CharacterNode  *p = NULL, CharacterNode  *n = NULL)
    {
        xter = x;
        prev = p;
        next = n;
    }
};

class Lineup
{
private:
    CharacterNode *head;//head node
    std::string name;
    int score;//to keep this lineup's score.

public:
    Lineup();
    bool isEmpty();
    void addBack(Character *);//addBack
    CharacterNode* getFront();
    Character* getXter(CharacterNode *);
    void removeFront();
    void printLineup();
    void setName(std::string);
    std::string getName();
    int getScore();
    void addToScore(int);//adds a number to the score.
    ~Lineup();
};

#endif