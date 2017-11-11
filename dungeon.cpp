#include "dungeon.h"

using namespace std;

Room* Dungeon::getCurrentRoom() const {
    return map[northSouthIndex][eastWestIndex];
}