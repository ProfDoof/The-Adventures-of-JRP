#include "room.h"
#include "enemy.h"
#include "character.h"
using namespace std;
Room::Room(int MonsterType, string RoomName, string RoomDesc, int dam)
{
	Adventurer = NULL;
	Monster = Enemy::createEnemy(MonsterType);
	Puzzle = NULL;
	Visited = false;
	Name = RoomName;
	Desc = RoomDesc;
	Damage = dam;
}

bool Room::visit() const
{
	return Visited;
}

void Room::visit(bool input)
{
	Visited = input;
}

string Room::roomname() const
{
	return Name;
}

void Room::roomname(string input)
{
	Name = input;
}

string Room::description() const
{
	return Desc;
}

void Room::description(string desc)
{
	Desc = desc;
}

void Room::AddToFloor(Item ttt)
{
	LooseItems.push_back(ttt);
}

/*
Item Room::TakeFrom()
{
	//How do I do this?
	
}
*/

int Room::Trap() const
{
	return Damage;
}

void Room::Trap(int input)
{
	Damage = input;
}

Curio* Room::LookAtCurio() const
{
	return Puzzle;
}

void Room::ChangeCurio(Curio* input)
{
	Puzzle = input;
}

Enemy* Room::CurrentEnemy() const
{
	return Monster;
}

void Room::ChangeEnemy(Enemy* input)
{
	Monster = input;
}
