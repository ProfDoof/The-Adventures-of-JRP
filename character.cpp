
#include "character.h"
#include <list>
#include <algorithm>
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

void DisplayItemCharacter(Item it)
{
	cout << it.Name() << " ";
}

void Character::CurrentInventory()
{
	for_each(inventory.begin(),inventory.end(), DisplayItemCharacter);
}

int Character::InventorySize()
{
	return inventory.size();
}