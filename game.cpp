#include "game.h"
#include "room.h"
#include <iostream>
using namespace std;
void Game::start()
{
	dung = new Dungeon();
}

void Game::run()
{

    cout << "Welcome... To the Dungeon!\n";
    cout << dung->getCurrentRoom()->description() << endl;
    char cmd;
    bool flag = true;
    while(flag) {
        cout << "Please enter a command. Enter \"?\" for a list of commands: ";   
        cin >> cmd;
        if(cmd == '?')
            cout << "You can look around the room with the command \"l\". \n"
                << "You can move North, South, East, or West with the commands \"n\", \"s\", \"e\", or \"w\" respectively. This will of course not work if there is no door that direction. \n"
                //<< "If there is a curio in the room, you can examine it with \"c\" \n"
                << "If there is a monster in the room, you can run away with \"r\" or attack with \"a\". \n";
                //<< "If there are items in the room, you may get a list of them with \"i\" and look at them closer with the number of the item in the room, for example \"1\" or \"5\".";
        else if(cmd == 'n' || cmd == 's' || cmd == 'e' || cmd == 'w')       
        {
            dung->move(cmd);
            cout << dung->getCurrentRoom()->description() << endl;
            if(dung->getCurrentRoom()->CurrentEnemy())
                combat(cmd,flag);
        }
        else if(cmd == 'l')
            cout << "This function is not yet supported.\n";       
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
        cout << "A." << endl;
        if(choice == 'a')
        {
            cout << "B." << endl;
            int enemyAtk = dung->getCurrentRoom()->CurrentEnemy()->ATK();
            int playerAtk = dung->getPlayer()->ATK();
            cout << "C." << endl;
            int enemyDef = dung->getCurrentRoom()->CurrentEnemy()->DEF();
            int playerDef = dung->getPlayer()->DEF();
            cout << "D." << endl;
            int enemyHp = dung->getCurrentRoom()->CurrentEnemy()->HP();
            int playerHp = dung->getPlayer()->HP();
            cout << "E." << endl;
            if((playerAtk - enemyDef) > enemyHp)
            {
                cout << "F." << endl;
                cout << "Congratulations, you have defeated " << dung->getCurrentRoom()->CurrentEnemy()->EnemyName() << endl;
                dung->getCurrentRoom()->ChangeEnemy(NULL);
                break;
            }
            cout << "G." << endl;
            cout << "You have done " << playerAtk << " damage.\n" << "The enemy has done " << enemyAtk << " damage." << endl;
            if(playerHp < (enemyAtk - playerDef))
            {
                cout << "You have died." << endl;
                cout << "Look, just try again... maybe, you'll succeed this time." << endl;
                flag = false;
                break;
            }                
              
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
