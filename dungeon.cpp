#include "room.h"
#include "enemy.h"
#include "character.h"
#include "dungeon.h"
using namespace std;

Dungeon::Dungeon() : northSouthIndex(3), eastWestIndex(0)
{
	player = new Character(40,20,30);
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
	Map[0][0] = new Room(0,"Storage Room","You are in a large storage room at the end of a hallway. There are some miscellaneous supplies lying around, but none seem pertinent to your quest. A broom leans against the wall next to a box. Inside the box is a number of feather dusters but you think there might be something underneath them. You think this may just be a broom closet. There is a door to the South, the one you came through."); //Armor
	Item BArmor("Leather Armor","Armor made of cured leather. Tough, but not likely to stay that way for more than a few hits. Increases defense by 10", 0,0,10);
	Map[0][0]->AddToFloor(BArmor);
	Map[0][2] = new Room(0,"Common Bedroom","You are in a common bedroom. It is fairly unremarkable, a small bed sits in the corner. A dresser and a wardrobe are on the opposite side of the room. There is a door leading South back to the hallway."); 
	Curio* temp = new Curio("Lockbox","This lockbox has a metal lock on it that seems like it could be opened by some kind of key.", "Bronze Key", "Inside the lockbox you find a note from Slave Master Homer saying \"Stop leaving your key down in my Dungeon, next time I won't return it\"");
	Map[0][2]->ChangeCurio(temp);
	Map[0][3] = new Room(0,"Meeting Room","You are in a large room with a table in the middle surrounded by chairs. It looks to have been a meeting room of some sort. There is a shelf with some papers on it. On closer inspection they appear to be old documents pertaining to business carried out by the castle. Nothing important to you. Lying on the table however, is a nice looking sword. There is a door leading back South."); //Sword
	Item StSword("Steel Sword","A hefty and well made sword forged of high quality steel. Provides 25 attack", 25,0,0);
	Map[0][3]->AddToFloor(StSword);
	Map[0][4] = new Room(0,"Storage Room","You are in a small storage room tucked in the side of the hallway. There are some cleaning supplies lying about in the close, but one looks kind of off to you. There's a bottle of red liquid that looks like it was made for drinking. The exit back to the hallway is to the South."); //Health Potion
	Item HPot("Health Potion","A red concoction that restores vitality. Will restore 50 HP.", 0,50,0);
	Map[0][4]->AddToFloor(HPot);
	Map[0][6] = new Room(10,"The Slave Master's Bedroom","You are in a rather opulent room with a high roof and fancy decorations. The bed is large and imperial, adorned with silken sheets and velvet drapery. A large dresser with a mirror of gold sits in the corner. There is a door to the South."); //Pendant(Increases DEF)
	Item Pend("Pendant","A small pendant that seems unremarkable at a glance, but contains great power. Grants a small defensive boost to the wearer.", 0,0,10);
	Map[0][6]->AddToFloor(Pend);
	//Row 1
	Map[1][0] = new Room(9,"Hallway","You are in a fairly unremarkable hallway in the lower dungeon. There are torches on both walls and you can see doors to the North, East, and South."); 
	Item BKey("Bronze Key","A key fashioned of bronze. Wonder what it opens?", 0,0,0);
	Map[1][0]->AddToFloor(BKey);
	Map[1][1] = new Room(0,"Hallway","You are in a well lit hallway in the upper dungeon. You are flanked by a number of cells on either side, all locked. The cells seem far better furnished and supplied than your own, perhaps this is where political prisoners were held? At the end of the hall you can see a door. There are exits to the East, and West."); 
	Map[1][2] = new Room(1,"Hallway","You are in a dark hallway. You cannot see what is in front of you.");
	Map[1][3] = new Room(0,"Hallway","You are in a hallway. There is nothing remarkable about this particular hallway, it looks like the others that you've been in. There are doors to the North, East, South, and West.");
	Map[1][4] = new Room(0,"Hallway","You are in yet another unremarkable hallway. You begin to ponder if whoever designed this place intended for there to be more paths than places that they lead. Doesn't really matter though. You spy three doors, one North, one East, and the other West.");
	Map[1][5] = new Room(0,"Hallway","You are in a strange hallway in the lower dungeon. There are stairs at the Eastern end of it! How curious. There is a door to the West.");
	Map[1][6] = new Room(0,"Hallway","You are in an important hallway in the lower dungeon. The hallway curves upward leading to the North. There is a heavy door. You suspect that this is an important room.");
	Map[1][8] = new Room(7,"Duke Byrd's Bedroom","You are in a grand bedroom of immeasurable opulency. Tapestries of Duke Byrd's heroism and greatness soar high up to the ceiling. Banners of his noble house fly high. The bed in the center of the room is carved of solid gold with soft silken sheets. Everywhere you look, more gold catches your eye. You spot a piece of paper on a golden dresser, next to the golden wardrobe. You ponder how this room hasn't collapsed under its own weight. There is a door leading back to the South"); //Slave Certificate
	//Row 2
	Map[2][0] = new Room(0,"Hallway","You are in a dark hallway in the lower dungeon. Flanking you on either side are small cells, all locked. They seem to be grimy and in about as bad shape as your own cell. It would seem that this is where common slaves and prisoners were held. About halfway down the hallway there is a dagger stuck in the wall. At the end of the hallway, there is a door leading North.");
	Item Dag("Dagger","A small iron dagger. Makes you feel a little safer.", 5,0,0);
	Map[2][0]->AddToFloor(Dag);
	Map[2][3] = new Room(0,"Hallway","You are in a fairly unremarkable hallway in the lower dungeon. There are torches on both walls and you can see doors at the North and South ends of the hallway.");
	Map[2][8] = new Room(0,"Hallway","You are in an opulent hallway with a gold adorned door at the end. You suspect that Duke Byrd lies beyond it, waiting for you. Before crossing the threshold, you take a moment to prepare yourself. The door is to the North, the way back is to the South and there is another door to the East.");
	Map[2][9] = new Room(11,"Guard Post","You are in an empty guard post. There are signs of recent activity, namely a half-eaten sandwich and a few open cabinets. On the table sits a guard helmet in good condition."); //Helmet
	Item Helm("Helmet","A sturdy closed face helmet. It'll protect your important head bits, but the rest of your bits are up to you.", 0,0,10);
	Map[2][9]->AddToFloor(Helm);
	//Row 3
	Map[3][0] = new Room(0,"Hallway","You are in a squalid and grimy room. One wall has a set of iron bars with a door set in them. You recognize this room as your cell, the place that you're confined when not being forced to work. There is a straw mat in the corner. There are doors to the North, East, and South.");
	Map[3][1] = new Room(0,"Hallway","You are in a hallway in the lower dungeon. There are some rats scurrying about, but nothing of note catches your eye. There are exits to the East and West.");
	Map[3][2] = new Room(0,"Hallway","You are in a hallway in the lower dungeon. It is utterly unremarkable in all regards, except for the old sword lying by one of the cells. There are doors to the East and West."); ///Sword
	Item RSword("Rusty Sword","Old and worn, don\'t expect to kill much with this. Adds 10 to attack.", 10,0,0);
	Map[3][2]->AddToFloor(RSword);
	Map[3][3] = new Room(8,"Hallway","You are in a hallway in the upper dungeon. It is fairly plain, though there is one cell near the northern end of the hallway. You can see part of a food tray sticking out from under the cell door. There are doors to the North, East, and West."); //Apple
	Item App1("Apple","A fresh and juicy apple, should be sufficient to deter any PhD holders in the area.", 0,20,0);
	Map[3][3]->AddToFloor(App1);
	Map[3][4] = new Room(0,"Hallway","You are in a hallway leading to the castle. It has a high ceiling and some tapestries depicting some generic scenes adorning the walls. There are doors to the East and West.");
	Map[3][5] = new Room(0,"Hallway","You are in a hallway in the castle. It is well lit and seems to be leading somewhere important. Just a hunch though. There are doors to the East, West, and South.");
	Map[3][6] = new Room(0,"Hallway","You are in a long hallway with a long table covered with a cloth. You notice that one of the trays on the table still has an apple on it. There are doors to the East and West."); //Apple
	Item App2("Apple","A nice and tasty apple. You love the taste of these things almost as much as you love HCI.", 0,20,0);
	Map[3][6]->AddToFloor(App2);
	Map[3][7] = new Room(0,"Hallway","You are in a hallway in the castle. It has doors at the East and West ends. A chandelier hangs from the ceiling. There seems to be something stuck to it, but you can't tell what.");
	Map[3][8] = new Room(8,"Hallway","You are in a hallway. It has doors at the North, South, and West ends. Two torches burn brightly.");
	//Row 4
	Map[4][0] = new Room(0,"Hallway","You are in a hallway in the lower dungeon. On the north door you can see a pair of scissors embedded in the wood, pinning a note in place. There are doors to the North and South.");
	Map[4][5] = new Room(4,"Hallway","You are in a hallway. It has doors at the North and South ends.");
	Map[4][8] = new Room(0,"Hallway","You are in a hallway in the upper dungeon. There is nothing of note here. There are doors to the North, East, and South.");
	Map[4][9] = new Room(12,"Lab","You are in what appears to be an alchemist's workshop. There are potiont of various make and effect lying around. You're not sure what any of them do, and you're not about to just drink some to find out. There is a door leading back out to the West.");
	//Row 5
	Map[5][0] = new Room(1,"Hallway","You are in a hallway in the upper dungeon. There is nothing of note here. There are doors to the North and South.");
	Map[5][2] = new Room(0,"Forge","You are in a large room with a forge set in the side. It doesn't look like anyone has made anything here in a while, however you spy the gleam of metal in the corner of the room. There is a door to the South and a storage closet to the East."); //Armor(Best)
	Item GArmor("Burton\'s Burly Burnished Brigandine","Powerful armor powered by forces many consider to be Unreal. Forged by wizards from the Jungle Lumberyard who came together with great Unity.", 0,0,100);
	Map[5][2]->AddToFloor(GArmor);
	Map[5][3] = new Room(0,"Storage Closet","You are in a storage closet tucked in to the side of the forge. There isn't very much in here. In the corner is a box with a stick poking out of the top."); //Sword(Best)
	Item GSword("Sword of St. Schubert","The legendary blade blessed by St. Schubert himself. Increases your damage by 100.", 100,0,0);
	Map[5][3]->AddToFloor(GSword);
	Map[5][5] = new Room(0,"Hallway","You are in an unremarkable hallway. There is a chandelier hanging from the ceiling, but it is unlit. There are doors to the North and South."); 
	Map[5][8] = new Room(0,"Hallway","You are in a hallway. It looks like most of the other hallways you've visited. There are doors to the North and South.");
	//Row 6
	Map[6][0] = new Room(0,"Hallway","You are in a hallway. There are no defining features, save for how utterly unremarkable it is. There are doors to the North and South.");
	Map[6][2] = new Room(14,"Hallway","You are in a hallway. It is devoid of useful material and mental stimulation. There are doors to the North and South.");
	Map[6][5] = new Room(0,"Hallway","You are in a hallway. There is a bear skin rug stretched across the floor. You worry about what you're going to do after you get out if this bear is local, seeing as its skin is about 20 feet long. There are doors to the North and South.");
	Map[6][8] = new Room(4,"Hallway","You are in a hallway. There is a window facing a large forest outside. There are doors to the North and South.");
	//Row 7
	Map[7][0] = new Room(0,"Hallway","You are in a hallway. There is a large door set in the wall to the West. It is locked. There are doors to the North and East.");
	Map[7][1] = new Room(1,"Hallway","You are in a hallway. The hallway fills you with hope and determination. Or maybe its just dust. Probably dust. There are doors to the East and West.");
	Map[7][2] = new Room(0,"Hallway","You are in a hallway. The hallway looks just like the previous hallway except there is a dead rat in this one. Marvelous. There are doors to the North, East, and West.");
	Map[7][3] = new Room(0,"Hallway","You are in a hallway. A sense of dread fills you when you look at this hallway. It is just as boring as the previous one. Imagine that. There are doors leading to the East and West.");
	Map[7][4] = new Room(0,"Hallway","You are in a normal hallway. There is a broken cell door on the floor here. There are doors to the East and West.");
	Map[7][5] = new Room(13,"Hallway","You are in a small hallway. It is uncomfortable to walk through, your shoulders scraping the sides if you aren't careful. There are doors to the North, East, and West.");
	Map[7][6] = new Room(0,"Hallway","You are in the least important hallway. There is absolutely nothing here. Just doors leading East and West.");
	Map[7][7] = new Room(0,"Hallway","You are in the empty hallway. Possibly the strangest hallway you've seen so far, it is completely bare and empty. No lights, no cells, nothing. The only defining features are the doors on the East and West ends.");
	Map[7][8] = new Room(0,"Hallway","You are in a blindingly bright hallway. You can barely make out a door to the East, one more to the West, and another to the North.");
	Map[7][9] = new Room(0,"Hallway","You are in a hallway that ends in a dead end wall. By the wall, sits an old skeleton, hand still grasping a nice looking sword. There is a door back to the West."); //Sword
	Item SSword("Silver Sword","A fine blade forged of alchemical silver that will never dull or rust. Can cut through any opposition. Grants 40 attack.", 40,0,0);
	Map[7][9]->AddToFloor(SSword);
}

void Dungeon::move(char direction)
{
	if(direction == 'n' && northSouthIndex-1 >= 0 && Map[northSouthIndex-1][eastWestIndex] != NULL)
		northSouthIndex--;
	else if(direction == 's' && northSouthIndex+1 < 8 && Map[northSouthIndex+1][eastWestIndex] != NULL)
		northSouthIndex++;
	else if(direction == 'e' && eastWestIndex+1 < 10 && Map[northSouthIndex][eastWestIndex+1] != NULL)
		eastWestIndex++;
	else if(direction == 'w' && eastWestIndex-1 >= 0 && Map[northSouthIndex][eastWestIndex-1] != NULL)
		eastWestIndex--;
	else
		cout << "There is no room you can go into in that direction... just, look, just try again..." << endl;
}

Character* Dungeon::getPlayer()
{
	return player;
}

Dungeon::~Dungeon()
{
	delete player;
	for( int i = 7; i >= 0; i-- )
	{
		for( int j = 9; j >= 0; j-- )
		{
			delete Map[i][j];
		}
		delete [] Map[i];
	}
	delete [] Map;
}
