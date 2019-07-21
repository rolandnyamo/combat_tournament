#include "character.hpp"
#include "vampire.hpp"
#include "harry.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "blueMen.hpp"
#include "menu.hpp"
#include "lineup.hpp"
#include <string>
#include <ctime>
// #include <cstdio>
#include <stdlib.h>

void setName(Character *);
char getYN();
std::string getName();
bool requireChar(std::string charInput);
void sleep(unsigned int);
int main()
{    
    int t1_chars = -1;//to hold the number of characters for teams 1.
    int t2_chars = -1;//to hold the number of characters for teams 2.

    Menu menu1("\n*****\n\nFantasy Combat Tournament\n\n*****\n\n", 2);
    menu1.setOptions(1, "Play");
    menu1.setOptions(2, "Quit");

    int g_choice = menu1.displayOptions();

    while (g_choice != 2)
    {
        std::string t1_name, t2_name;
        Lineup *team1 = new Lineup;
        Lineup *team2 = new Lineup;
        Lineup *loser_lineup = new Lineup;
        loser_lineup->setName("Loser");

        std::cout << "\n\nSet a name for Team 1: ";
        team1->setName(getName());//using my getname() helper function (at the bottom) to set the names
        t1_name = team1->getName();

        std::cout << "\nSet a name for Team 2: ";
        team2->setName(getName()); 
        t2_name = team2->getName();

        std::cout << "\nHow many characters for Team \"" << t1_name << "\"? max 10: ";
        t1_chars = menu1.getInt();

        while (t1_chars < 1 || t1_chars > 10)
        {
            std::cout <<"\nMust be 1-10.\n\nEnter value: ";
            t1_chars = menu1.getInt();
        }
        
        std::cout << "How many characters for Team \"" << t2_name << "\"? max 10: ";
        t2_chars = menu1.getInt();

        while (t2_chars < 1 || t2_chars > 10)
        {
            std::cout <<"\nMust be 1-10.\n\nEnter value: ";
            t2_chars = menu1.getInt();
        }


        //. Get team characters and add them to lineups
        if (g_choice == 1)
        {
            int c1_choice = -1;//lineup 1 chouce menu
            int c2_choice = -1;//lineup 2 choice menu

            Menu menu2("\nChoose your " + t1_name + "  Character\n", 5);

            menu2.setOptions(1,"Vampire");
            menu2.setOptions(2,"Barbarian");
            menu2.setOptions(3,"Blue Men");
            menu2.setOptions(4,"Medusa");
            menu2.setOptions(5,"Harry Potter");

            for (int i = 0; i < t1_chars; i++)
            {
                c1_choice = menu2.displayOptions();

                if (c1_choice == 1)
                {
                    Character *c = new Vampire();
                    setName(c);
                    c->setTeam(team1->getName());

                    std::cout << "\n...adding " <<
                    c->getName() << " to " << t1_name << " Lineup\n";
                    team1->addBack(c);
                }
                else if (c1_choice == 2)
                {
                    Character *c = new Barbarian();
                    setName(c);
                    c->setTeam(team1->getName());

                    std::cout << "\n...adding " <<
                    c->getName() << " to " << t1_name << " Lineup\n";
                    team1->addBack(c);
                }
                else if (c1_choice == 3)
                {
                    Character *c = new Bluemen();
                    setName(c);
                    c->setTeam(team1->getName());

                    std::cout << "\n...adding " <<
                    c->getName() << " to " << t1_name << " Lineup\n";
                    team1->addBack(c);
                }
                else if (c1_choice == 4)
                {
                    Character *c = new Medusa();
                    setName(c);
                    c->setTeam(team1->getName());

                    std::cout << "\n...adding " <<
                    c->getName() << " to " << t1_name << " Lineup\n";
                    team1->addBack(c);
                }
                else if (c1_choice == 5)
                {
                    Character *c = new Harry();
                    setName(c);
                    c->setTeam(team1->getName());

                    std::cout << "\n...adding " <<
                    c->getName() << " to " << t1_name << " Lineup\n";
                    team1->addBack(c);
                }
            }
            c1_choice = 6;//invalid team1 lineup menu choice to reactivate the menu if needed

            //print Team 1 lineup
            team1->printLineup();

            std::cout << "\n\n\nDone with " << t1_name << 
            ", let's set up \"" << t2_name << "\"" << std::endl;
                       
            Menu menu3("\nChoose your " + t2_name + " Character\n", 5);

            menu3.setOptions(1,"Vampire");
            menu3.setOptions(2,"Barbarian");
            menu3.setOptions(3,"Blue Men");
            menu3.setOptions(4,"Medusa");
            menu3.setOptions(5,"Harry Potter");

            for (int i = 0; i < t2_chars; i++)
            {
                c2_choice = menu3.displayOptions();

                if (c2_choice == 1)
                {
                    Character *c2 = new Vampire();
                    setName(c2);
                    c2->setTeam(team2->getName());

                    std::cout << "\n...adding " <<
                    c2->getName() << " to " << t2_name << " Lineup\n";
                    team2->addBack(c2);                        
                }
                else if (c2_choice == 2)
                {
                    Character *c2 = new Barbarian();
                    setName(c2);
                    c2->setTeam(team2->getName());

                    std::cout << "\n...adding " <<
                    c2->getName() << " to " << t2_name << " Lineup\n";
                    team2->addBack(c2);
                }
                else if (c2_choice == 3)
                {
                    Character *c2 = new Bluemen();
                    setName(c2);
                    c2->setTeam(team2->getName());

                    std::cout << "\n...adding " <<
                    c2->getName() << " to " << t2_name << " Lineup\n";
                    team2->addBack(c2);
                }
                else if (c2_choice == 4)
                {
                    Character *c2 = new Medusa();
                    setName(c2);
                    c2->setTeam(team2->getName());

                    std::cout << "\n...adding " <<
                    c2->getName() << " to " << t2_name << " Lineup\n";
                    team2->addBack(c2);
                
                }
                else if (c2_choice == 5)
                {
                    Character *c2 = new Harry();
                    setName(c2);
                    c2->setTeam(team2->getName());

                    std::cout << "\n...adding " <<
                    c2->getName() << " to " << t2_name << " Lineup\n";
                    team2->addBack(c2);
                
                }
            }  
            c1_choice = 6;          

            //print Team 2 lineup
            team2->printLineup();
        }

        //Gameplay
        //set player 1 and player 2
        CharacterNode *p1Node = team1->getFront();
        CharacterNode *p2Node = team2->getFront();
        
        Character *p1, *p2;
        p1 = p1Node->xter;
        p2 = p2Node->xter;
        int rounds = 1;
        bool play = true;

        //Fight!

        while (play)
        {

            std::cout << "\nRound: " << rounds << std::endl;
            std::cout << "\n";
            std::cout << "******\n\n";
            p1->attack(p2);

            if (p2->isDead())
            {
                loser_lineup->addBack(p2);
                team2->removeFront();

                //add p2 to loser lineup
                //remove front from p2
                //app p1 to back of team 1
                //remove front from t1
                
                if (team2->isEmpty())
                {
                    play = false;
                }
                else
                {
                    team1->addBack(p1);//push p1 to the back of team 1
                    team1->removeFront();//remove p1 from the front of team 1
                    p2Node = team2->getFront();
                    p2 = p2Node->xter;
                }
                
                p1->won();

                team1->addToScore(1);
                std::cout << p1->getName() << " is recovering...\n";                
                p1->recover();//recover the winner's strength
                std::cout << "\n\n" << p1->getName() << "\'s new strength is is " << p1->getStrength()
                << std::endl;

                p1Node = team1->getFront();
                p1 = p1Node->xter;
            }
            else
            {
                std::cout << "\n*\n";
                p2->attack(p1);

                if (p1->isDead())
                {
                    loser_lineup->addBack(p1);
                    team1->removeFront();

                    if (team1->isEmpty())
                    {
                        play = false;
                    }
                    else
                    {
                        team2->addBack(p2);//push p2 to the back of team 2
                        team2->removeFront();//remove p2 from the front of team 2                       
                        p1Node = team1->getFront();
                        p1 = p1Node->xter;
                    }

                    p2->won();

                    team2->addToScore(1);
                    std::cout << p2->getName() << " is recovering...\n";                
                    p2->recover();//recover the winner's strength
                    std::cout << "\n\n" << p2->getName() << "\'s new strength is is " << p2->getStrength()
                    << std::endl;  

                    p2Node = team2->getFront();
                    p2 = p2Node->xter;                                 
                }
            }

            std::cout << "******\n\n";

            sleep(2);

            rounds ++;
        }

        if (team1->getScore() > team2->getScore())
        {
            std::cout << "\nTeam " << team1->getName() << " won in " << rounds << 
            " rounds!\n\nFinal score:\n" << team1->getName() << ": " << team1->getScore() 
            << "      " << team2->getName() << ": " << team2->getScore() << std::endl;
        }
        else
        {
            std::cout << "\nTeam " << team2->getName() << " won in " << rounds << 
            " rounds!\n\nFinal score:\n" << team1->getName() << ": " << team1->getScore() 
            << "      " << team2->getName() << ": " << team2->getScore() << std::endl;
        }
        std::cout << "\n\nWould you like to print the loser lineup? y/n:";
        char ans = getYN();

        if (ans == 'y')//print the loser lineup only for the lineup that's not empty
        {
            if (!(loser_lineup->isEmpty()))
            {
                loser_lineup->printLineup();
            }
            else
            {
                std::cout << "\nWeird. There are no losers" << std::endl;
            }
        }
        else
        {
            std::cout << "\nGoing back to main menu\n\n";
        }

        //. delete dynamically allocated memory 
        delete team1;
        delete team2;
        team1 = NULL;
        team2 = NULL;

        delete loser_lineup;
        loser_lineup = NULL;

        g_choice = menu1.displayOptions();

    }

    std::cout << "\n\nGoodbye!\n\n";
}

//. description: sleep function to give srand time to seed.
//. adapted from https://ubuntuforums.org/showthread.php?t=296142
void sleep(unsigned int msec)
{
    clock_t my_time = msec * 1000000 + clock();
    while (my_time > clock());
}
//. adapted from past group project
bool requireChar(std::string charInput)
{
	return charInput.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 \'\".-_+!#@?><:$^&*=") == std::string::npos;
}

//. y/y helper function
bool requireyn(std::string charInput)
{
	return charInput.find_first_not_of("yn") == std::string::npos;
}

//. gets y/n from the user

char getYN()
{
    std::string answer;
    std::getline(std::cin, answer);
    std::cin.clear();
    bool valid = requireyn(answer);

    while (!valid || (answer.empty()))
    {
        std::cout << "Enter 'y' or 'n': ";
        std::getline(std::cin, answer);
        std::cin.clear();
        valid = requireyn(answer);
    }

    return answer[0];
}
//. gets string input from the user for the character and team name
std::string getName()
{
    std::string answer;
    std::getline(std::cin, answer);
    std::cin.clear();
    bool valid = requireChar(answer);

    while (!valid || (answer.empty()))
    {
        std::cout << "Enter a valid name: ";
        std::getline(std::cin, answer);
        std::cin.clear();
        valid = requireChar(answer);
    }

    return answer;
}
//. setter for a character or team name
void setName(Character *c)
{
    std::cout << "Would you like to set a name for the " << c->getType() <<
    " character? y/n:";
    char ans = getYN();

    if (ans == 'y')
    {
        std::cout << "\nName: ";
        c->setName(getName());
    }
    else
    {
        std::cout << "\nThe default name of " << c->getName() <<
        " will apply for the charactger.\n";
    }
}