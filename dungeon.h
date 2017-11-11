#ifndef DUNGEON_H
#define DUNGEON_H
#include "room.h"

class Dungeon{
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
};

#endif
