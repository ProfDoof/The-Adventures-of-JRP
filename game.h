#ifndef GAME_H
#define GAME_H
#include "dungeon.h"
#include "room.h"
class Game {
	private:
<<<<<<< HEAD
		//Dungeon WIIA;
=======
>>>>>>> 9248026c51717271355077f461425c8897afa27d
        Dungeon* dung;
        static Game* g_instance;
        Game();
	public:
        static Game* instance() {
            if (!g_instance) 
                g_instance = new Game();
            return g_instance;
        }

		//Initializer for the entire game
		void start();
		//Where the game actually starts running
		void run();
		//Where we start destroying things
		void end();
};
#endif
