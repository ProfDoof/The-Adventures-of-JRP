#include "item.h"
#include "item.cpp"
#include "character.h"
using namespace std;
//setters and getters for the things
int ATK() const
{
	return atkpoints;
}

void ATK(int input)
{
	atkpoints = input;
}

int DEF() const
{
	return defpoints;
}

void DEF(int input)
{
	defpoints = input;
}

int HP() const
{
	return hitpoints;
}

void HP(int input)
{
	hitpoints = input;
}

void AddToInventory(Item push)
{
	for( int i = 0; i < invsize; i++ )
	{
		if( inventory[i] = NULL )
		{
			inventory[i] = push;
		}
	}
}

//functions
void Attack(Character* enemy)
{
	int current = this->HP();
	int enemyCurrent = enemy.HP();
	int dmg = this->ATK() - enemy.DEF();
	int enemyDmg = enemy.ATK() - this->DEF();
	current -= enemyDmg;
	enemyCurrent -= dmg;
	this->HP(current);
	enemy.HP(enemyCurrent);
}

//testing code
int main()
{

}