#include "room.h"
#include "enemy.h"
#include "character.h"
#include "dungeon.h"
using namespace std;

Dungeon::Dungeon() : northSouthIndex(3), eastWestIndex(0)
{
	player = new Character(10,10,10);
	Map = new Room** [8];
	for( int i = 0; i < 8; i++ )
	{
		Map[i] = new Room* [10];
		for( int j = 0; j < 10; j++ )
		{
			Map[i][j] = NULL;
		}
	}


	//Format is that you create a new room and then can push any items in that you want in that room.
	//Row 0
	Map[0][0] = new Room(0,"Storage Room",""); //Armor
	Map[0][2] = new Room(4,"Common Bedroom",""); 
	Map[0][3] = new Room(0,"Meeting Room",""); //Sword
	Map[0][4] = new Room(0,"Storage Room",""); //Health Potion
	Map[0][6] = new Room(10,"The Slave Master's Bedroom",""); //Pendant(Increases DEF)
	//Row 1
	Map[1][0] = new Room(9,"Hallway",""); 
	Map[1][1] = new Room(0,"Hallway",""); 
	Map[1][2] = new Room(1,"Hallway","");
	Map[1][3] = new Room(0,"Hallway","");
	Map[1][4] = new Room(0,"Hallway","");
	Map[1][5] = new Room(0,"Hallway","");
	Map[1][6] = new Room(0,"Hallway","");
	Map[1][8] = new Room(7,"Duke Byrd's Bedroom",""); //Slave Certificate
	//Row 2
	Map[2][0] = new Room(0,"Hallway","");
	Map[2][3] = new Room(0,"Hallway","");
	Map[2][8] = new Room(0,"Hallway","");
	Map[2][9] = new Room(11,"Guard Post",""); //Helmet
	//Row 3
	Map[3][0] = new Room(0,"Hallway","Hi, I'm working");
	Map[3][1] = new Room(0,"Hallway","Hi, I'm working");
	Map[3][2] = new Room(0,"Hallway","Hi, I'm working"); ///Sword
	Map[3][3] = new Room(8,"Hallway","Hi, I'm working"); //Apple
	Map[3][4] = new Room(0,"Hallway","Hi, I'm working");
	Map[3][5] = new Room(0,"Hallway","Hi, I'm working");
	Map[3][6] = new Room(0,"Hallway","Hi, I'm working"); //Apple
	Map[3][7] = new Room(0,"Hallway","Hi, I'm working");
	Map[3][8] = new Room(8,"Hallway","Hi, I'm working");
	//Row 4
	Map[4][0] = new Room(0,"Hallway","Hi, I'm working");
	Map[4][5] = new Room(4,"Hallway","Hi, I'm working");
	Map[4][8] = new Room(0,"Hallway","Hi, I'm working");
	Map[4][9] = new Room(12,"Hallway","");
	//Row 5
	Map[5][0] = new Room(1,"Hallway","");
	Map[5][2] = new Room(0,"Forge",""); //Armor(Best)
	Map[5][3] = new Room(0,"Storage Closet",""); //Sword(Best)
	Map[5][5] = new Room(0,"Hallway",""); 
	Map[5][8] = new Room(0,"Hallway","");	
	//Row 6
	Map[6][0] = new Room(0,"Hallway","");
	Map[6][2] = new Room(14,"Hallway","");
	Map[6][5] = new Room(0,"Hallway","");
	Map[6][8] = new Room(4,"Hallway","");
	//Row 7
	Map[7][0] = new Room(0,"Hallway","");
	Map[7][1] = new Room(1,"Hallway","");
	Map[7][2] = new Room(0,"Hallway","");
	Map[7][3] = new Room(0,"Hallway","");
	Map[7][4] = new Room(0,"Hallway","");
	Map[7][5] = new Room(1,"Hallway","");
	Map[7][6] = new Room(0,"Hallway","");
	Map[7][7] = new Room(0,"Hallway","");
	Map[7][8] = new Room(0,"Hallway","");
	Map[7][9] = new Room(0,"Hallway",""); //Sword
}

void Dungeon::move(char direction)
{
	if(direction == 'n' && Map[northSouthIndex-1][eastWestIndex] != NULL)
		northSouthIndex--;
	else if(direction == 's' && Map[northSouthIndex+1][eastWestIndex] != NULL)
		northSouthIndex++;
	else if(direction == 'e')
		eastWestIndex++;
	else if(direction == 'w')
		eastWestIndex--;
}

Character* Dungeon::getPlayer()
{
	return player;
}