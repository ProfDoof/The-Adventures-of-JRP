#include "game.h"
#include "room.h"
#include <string>
#include <iostream>
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
        cout << "What do you do? Enter \"?\" for a list of commands: ";
        getline(cin,input);
        stringstream ss;
        ss << input;
        ss >> cmd;
        cout << "\n";
        toLower(cmd);
        if(cmd == "?")
            cout << "You can look around the room with the command \"Look\". \n"
                << "You can move North, South, East, or West with the command Move, then the direction: \"North\", \"South\", \"East\", or \"West\". This will of course not work if there is no door that direction. \n"
                //<< "If there is a curio in the room, you can examine it with \"c\" \n"
                << "If there is a monster in the room, you can run away with \"Run\" or attack with \"Attack\". \n"
                << "If you wish to see your current stats you can use the command \"Stats\"\n"
                << "If you want to exit the game you can do so with the command \"Exit\"\n";
                //<< "If there are items in the room, you may get a list of them with \"i\" and look at them closer with the number of the item in the room, for example \"1\" or \"5\".";
        else if(cmd == "move")       
        {
            ss >> action;
            toLower(action);
            dung->move(action[0]);
            cout << dung->getCurrentRoom()->description() << endl;
            if(dung->getCurrentRoom()->CurrentEnemy())
            {
                cout << "You have been attacked by " << dung->getCurrentRoom()->CurrentEnemy()->EnemyName() << endl;
                combat(action[0],flag);
            }        
        }
        else if(cmd == "look")
            cout << look() << endl;
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
    cout << dung->getCurrentRoom()->CurrentEnemy()->EncounterLine() << endl;
    cout << "You are now in combat, you can either run or attack" << endl;
    getline(cin,choice);
    toLower(choice);
    while(true)
    {    
        if(choice == "attack")
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
            
            break;
        }
        cin >> choice;
    }  
}

string Game::look()
{
    return dung->getCurrentRoom()->description();
}