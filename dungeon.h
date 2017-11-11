#ifndef DUNGEON_H
#define DUNGEON_H
#include "room.h"

class Dungeon{
	private:
		    Room*** Map;
        Character* player;
        int northSouthIndex;
        int eastWestIndex;
	public:
        Dungeon();
        Room* getCurrentRoom() const;
        void move( char direction );
        Character* getPlayer();
    

};

#endif
