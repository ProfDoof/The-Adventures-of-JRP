#include "game.h"
#include "room.h"
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void Game::start()
{
	dung = new Dungeon();
}

void Game::run()
{

    cout << "Welcome... To the Dungeon!\n\nYour game starts NOW!!!!!!\n\n";
    cout << dung->getCurrentRoom()->description() << endl;
    char cmd;
    bool flag = true;
    while(flag) {
        cout << "What do you do? Enter \"?\" for a list of commands: ";   
        cin >> cmd;
        cout << "\n";
        if(cmd == '?')
            cout << "You can look around the room with the command \"l\". \n"
                << "You can move North, South, East, or West with the commands \"n\", \"s\", \"e\", or \"w\" respectively. This will of course not work if there is no door that direction. \n"
                //<< "If there is a curio in the room, you can examine it with \"c\" \n"
                << "If there is a monster in the room, you can run away with \"r\" or attack with \"a\". \n"
                << "If you wish to see your current stats you can use the command \"q\"\n"
                << "If you want to exit the game you can do so with the command \"x\"\n";
                //<< "If there are items in the room, you may get a list of them with \"i\" and look at them closer with the number of the item in the room, for example \"1\" or \"5\".";
        else if(cmd == 'n' || cmd == 's' || cmd == 'e' || cmd == 'w')       
        {
            dung->move(cmd);
            cout << dung->getCurrentRoom()->description() << endl;
            if(dung->getCurrentRoom()->CurrentEnemy())
            {
                cout << "You have been attacked by " << dung->getCurrentRoom()->CurrentEnemy()->EnemyName() << endl;
                combat(cmd,flag);
            }        
        }
        else if(cmd == 'l')
            cout << look() << endl;
        else if(cmd == 'q') 
            cout << "Health: " << dung->getPlayer()->HP()
                 << " Defense: " << dung->getPlayer()->DEF()
                 << " Attack: " << dung->getPlayer()->ATK() << endl;
        else if(cmd == 'x')
        {    
            cout << "Exiting Game..." << endl;
            flag = false;
        }   
        else if(cmd == 't')
        {
            grab();
        }
        else if(cmd == 'd')
        {
            cout << "Debug Mode Activated" << endl;
            dung->getPlayer()->ATK(999);
            dung->getPlayer()->DEF(999);
            dung->getPlayer()->HP(999);
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
    char choice;
    cout << dung->getCurrentRoom()->CurrentEnemy()->EncounterLine() << endl;
    cout << "You are now in combat, you can either run(\"r\") or attack(\"a\")" << endl;
    cin >> choice;
    while(true)
    {    
        if(choice == 'a')
        {
            int enemyAtk = dung->getCurrentRoom()->CurrentEnemy()->ATK();
            int playerAtk = dung->getPlayer()->ATK();
            int enemyDef = dung->getCurrentRoom()->CurrentEnemy()->DEF();
            int playerDef = dung->getPlayer()->DEF();
            int enemyHp = dung->getCurrentRoom()->CurrentEnemy()->HP();
            int playerHp = dung->getPlayer()->HP();
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
        else if(choice == 'r')
        {
            if(direction == 'n')
                dung->TBI(1);
            else if(direction == 's')
                dung->TBI(-1);
            else if(direction == 'e')
                dung->LRI(-1);
            else if(direction == 'w')
                dung->LRI(1);
            
            break;
        }
        cin >> choice;
    }  
}

string Game::look()
{
    return dung->getCurrentRoom()->description();
}

void Game::grab()
{
    string itemname;
    cout << "What item would you like to take? ";
    getline(cin,itemname);
    Item temp = dung->getCurrentRoom()->TakeFrom(itemname);
    if(temp == "Error")
        cout << "That is not a recognized item... Try again.";
    else
    {
        dung->getPlayer()->AddToInventory(temp);
    }
}