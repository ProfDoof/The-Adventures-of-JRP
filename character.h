#include <list>
using namespace std;

class Character{
	private:
		int hitpoints;
		int defpoints;
		int atkpoints;
		list<Item> inventory;

	public:
		//Constructor
		Character(int hp, int de, int at) : hitpoints(hp), defpoints(de), atkpoints(at) {}
		//setters and getters for the things
		int ATK() const;
		void ATK(int input);

		int DEF() const;
		void DEF(int input);

		int HP() const;
		void HP(int input);

		void AddToInventory(Item push);

		//functions
		void Attack(Character* enemy);

};
