#include "game.h"
#include <iostream>
using namespace std;
void Game::start()
{
	dung = new Dungeon();
}

void Game::run()
{

    cout << "Welcome... To the Dungeon!\n";
    cout << dung->getCurrentRoom()->description();
    char cmd;
    while(true) {
        cout << "Please enter a command. Enter \"?\" for a list of commands: ";
        cin >> cmd;
        switch (cmd) {
            case '?': 
                cout << "You can look around the room with the command \"l\". \n"
                    << "You can move North South East or West with the commands \"n\", \"s\", \"e\", or \"w\" respectively. This will of course not work if there is no door that direction. \n"
                    << "If there is a curio in the room, you can examine it with \"c\" \n"
                    << "If there is a monster in the room, you can run away with \"r\" or attack with \"a\". \n"
                    << "If there are items in the room, you may get a list of them with \"i\" and look at them closer with the number of the item in the room, for example \"1\" or \"5\".";
            default:
                cout << "Unrecognized input. Please try again: ";
        }
    }
}

void Game::end()
{

}

