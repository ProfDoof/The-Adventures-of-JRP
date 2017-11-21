#include "game.h"
#include "room.h"
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;
void Game::start()
{
	dung = new Dungeon();
}

string toLower (string& s)
{
    for (int x = 0; s[x] != 0; x++)
        s[x] = tolower(s[x]);
    return s;
}

void Game::run()
{

    cout << "Welcome... To the Dungeon!\n\nYour game starts NOW!!!!!!\n\n";
    cout << dung->getCurrentRoom()->description() << endl;
    string cmd;
    string input;
    string action;
    bool flag = true;
    while(flag) {
        cout << "What do you do? Enter \"Help\" for a list of commands: ";
        getline(cin,input);
        stringstream ss;
        ss << input;
        ss >> cmd;
        cout << "\n";
        toLower(cmd);
        if(cmd == "help")
            cout << "You can look around the room with the command \"Look\". \n"
                << "You can move North, South, East, or West with the command \"Move\", then the direction: \"North\", \"South\", \"East\", or \"West\". This will of course not work if there is no door that direction. \n"
                //<< "If there is a curio in the room, you can examine it with \"c\" \n"
                << "If there is a monster in the room, you can run away with \"Run\" or attack with \"Attack\". \n"
                << "If you wish to see your current stats you can use the command \"Stats\"\n"
                << "If you want to exit the game you can do so with the command \"Exit\"\n"
                << "If there are items in the room, you may get a list of them with \"Look\".\n";
        else if(cmd == "move")       
        {
            ss >> action;
            toLower(action);
            dung->move(action[0]);
            cout << dung->getCurrentRoom()->description() << endl;
            cout << endl;
            if(dung->getCurrentRoom()->CurrentEnemy())
            {
                cout << "You have been attacked by " << dung->getCurrentRoom()->CurrentEnemy()->EnemyName() << endl;
                combat(action[0],flag);
            }        
        }
        else if(cmd == "take")
        {
            string placer;
            string itemname;
            ss >> itemname;
            while(ss >> placer)
            {
                itemname += " " + placer;
            }

            grab(itemname);
        }
        else if(cmd == "look")
            look();
        else if(cmd == "stats") 
            cout << "Health: " << dung->getPlayer()->HP()
                 << " Defense: " << dung->getPlayer()->DEF()
                 << " Attack: " << dung->getPlayer()->ATK() << endl;
        else if(cmd == "up,up,down,down,left,right,left,right,b,a,start" || cmd == "yeet")
        {
            cout << "Debug Mode Activated" << endl;
            dung->getPlayer()->ATK(999);
            dung->getPlayer()->DEF(999);
            dung->getPlayer()->HP(999);
        }
        else if(cmd == "inventory")
        {
            dung->getPlayer()->CurrentInventory();
        }
        else if(cmd == "exit")
        {    
            cout << "Exiting Game..." << endl;
            flag = false;
        }    
        else
            cout << "Unrecognized input. Please try again: ";
	}
    
}

void Game::end()
{

}

void Game::combat(char direction, bool& flag)
{
    string choice;
    int enemyAtk = dung->getCurrentRoom()->CurrentEnemy()->ATK();
    int playerAtk = dung->getPlayer()->ATK();
    int enemyDef = dung->getCurrentRoom()->CurrentEnemy()->DEF();
    int playerDef = dung->getPlayer()->DEF();
    int enemyHp = dung->getCurrentRoom()->CurrentEnemy()->HP();
    int playerHp = dung->getPlayer()->HP();
    cout << dung->getCurrentRoom()->CurrentEnemy()->EncounterLine() << endl;
    cout << "Your current stats are Health: " << playerHp << " Attack: " << playerAtk << " Defense: " << playerDef << endl;
    cout << "Your enemy's stats are Health: " << enemyHp << " Attack: " << enemyAtk << " Defense: " << enemyDef << endl;
    cout << "You are now in combat, you can either \"Run\" or \"Attack\"" << endl;
    getline(cin,choice);
    toLower(choice);
    while(true)
    {    
        if(choice == "attack")
        {
            enemyAtk = dung->getCurrentRoom()->CurrentEnemy()->ATK();
            playerAtk = dung->getPlayer()->ATK();
            enemyDef = dung->getCurrentRoom()->CurrentEnemy()->DEF();
            playerDef = dung->getPlayer()->DEF();
            enemyHp = dung->getCurrentRoom()->CurrentEnemy()->HP();
            playerHp = dung->getPlayer()->HP();
            if((playerAtk - enemyDef) >= enemyHp)
            {
                cout << "Congratulations, you have defeated " << dung->getCurrentRoom()->CurrentEnemy()->EnemyName() << endl;
                dung->getCurrentRoom()->ChangeEnemy(NULL);
                break;
            }
            cout << "You have done " << playerAtk - enemyDef << " damage.\n" << "The enemy has done " << enemyAtk - playerDef<< " damage." << endl;
            if(playerHp <= (enemyAtk - playerDef))
            {
                cout << "You have died." << endl;
                cout << "Look, just try again... maybe, you'll succeed this time." << endl;
                flag = false;
                break;
            }
            dung->getPlayer()->HP(playerHp - (enemyAtk - playerDef));
            dung->getCurrentRoom()->CurrentEnemy()->HP(enemyHp - (playerAtk - enemyDef));
              
        }    
        else if(choice == "run")
        {
            cout << "You have successfully escaped from combat!" << endl;
            if(direction == 'n')
                dung->TBI(1);
            else if(direction == 's')
                dung->TBI(-1);
            else if(direction == 'e')
                dung->LRI(-1);
            else if(direction == 'w')
                dung->LRI(1);
            
            return;
        }
        else
            cout << "Invalid Input" << endl;
        getline(cin,choice);
        toLower(choice);
    }  
}

void Game::look()
{
    cout << dung->getCurrentRoom()->description() << endl;
    cout << "Here is a list of the items in the room: ";
    dung->getCurrentRoom()->DescribeItems();
    cout << endl;
}

void Game::grab(string itemname)
{
    //Will need updates to work with the parser
    Item temp = dung->getCurrentRoom()->TakeFrom(itemname);
    if(temp == "Error")
        cout << "That is not a recognized item... Try again.";
    else
    {;
        int playerAtk = dung->getPlayer()->ATK();
        int playerDef = dung->getPlayer()->DEF();
        int playerHp = dung->getPlayer()->HP();
        dung->getPlayer()->AddToInventory(temp);
        if(temp.Healing() > 0)
        {
            cout << "Your health increases by " << temp.Healing() << " points." << endl;
            dung->getPlayer()->HP(playerHp + temp.Healing());
        }    
        if(temp.Defense() > 0)
        {
            cout << "Your defense increases by " << temp.Defense() << " points." << endl;
            dung->getPlayer()->DEF(playerDef + temp.Defense());
        }
        if(temp.Damage() > 0)
        {
            cout << "Your attack increases by " << temp.Damage() << " points." << endl;
            dung->getPlayer()->ATK(playerAtk + temp.Damage());
        }


    }
}