#include <list>
using namespace std;

class Character{
	private:
		int hitpoints;
		int defpoints;
		int atkpoints;
		int score;
		list<Item> inventory;

	public:
		//Constructor
		Character(int hp, int de, int at) : hitpoints(hp), defpoints(de), atkpoints(at) {score = 0;}
		//setters and getters for the things
		int ATK() const;
		void ATK(int input);

		int DEF() const;
		void DEF(int input);

		int HP() const;
		void HP(int input);

		int Score() const;
		void Score(int input);

		void AddToInventory(Item push);

		//functions
		/*void Attack(Character enemy);*/

};
