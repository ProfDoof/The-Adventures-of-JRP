
#include "character.h"
using namespace std;
//setters and getters for the things
int Character::ATK() const
{
	return atkpoints;
}

void Character::ATK(int input)
{
	atkpoints = input;
}

int Character::DEF() const
{
	return defpoints;
}

void Character::DEF(int input)
{
	defpoints = input;
}

int Character::HP() const
{
	return hitpoints;
}

void Character::HP(int input)
{
	hitpoints = input;
}

int Character::Score() const
{
	return score;
}

void Character::Score(int input)
{
	score = input;
}

void Character::AddToInventory(Item push)
{
	inventory.push_back(push);
}


//functions
/*void Character::Attack(Character enemy)
{
	int current = this->HP();
	int enemyCurrent = enemy.HP();
	int dmg = this->ATK() - enemy.DEF();
	int enemyDmg = enemy.ATK() - this->DEF();
	current -= enemyDmg;
	enemyCurrent -= dmg;
	enemy.HP(enemyCurrent);
	this->HP(current);
}*/

