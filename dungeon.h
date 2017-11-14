#ifndef DUNGEON_H
#define DUNGEON_H
#include "room.h"

class Dungeon{
      private:
        Room ***Map;
        Character* player;
        int northSouthIndex;
        int eastWestIndex;

      public:
        Dungeon();
        ~Dungeon();
        Room* getCurrentRoom() const { return Map[northSouthIndex][eastWestIndex];}
        void move(char direction);
        Character* getPlayer();
        int LRI() {return eastWestIndex;}
        void LRI(int input) {if( eastWestIndex < 10 && eastWestIndex >= 0 ) eastWestIndex+=input;}
        int TBI() {return northSouthIndex;}
        void TBI(int input) {if( northSouthIndex < 8 && northSouthIndex >= 0 ) northSouthIndex+=input;}
};

#endif
