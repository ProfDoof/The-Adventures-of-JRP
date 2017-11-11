#ifndef DUNGEON_H
#define DUNGEON_H
#include "room.h"

class Dungeon{
<<<<<<< HEAD
      private:
        Room ***map;
        Character *player;
        int northSouthIndex;
        int eastWestIndex;

      public:
        Dungeon() : northSouthIndex(3), eastWestIndex(0){};
        Room* getCurrentRoom() const;
        void move(char direction);
        Character *getPlayer();
=======
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
    

>>>>>>> 9248026c51717271355077f461425c8897afa27d
};

#endif
