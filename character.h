#include <list>


class Character{
	private:
		int hitpoints;
		int atkpoints;
		int defpoints;
		list<Item> inventory;

	public:
		//Constructor
		Character(int hp, int at, int de) : hitpoints(hp), atkpoints(at), defpoints(de) {}
		//setters and getters for the things
		int ATK() const;
		void ATK(int input);

		int DEF() const;
		void DEF();

		int HP() const;
		void HP();

		void AddToInventory(Item* push);

		//functions
		void Attack(Character* enemy);

};