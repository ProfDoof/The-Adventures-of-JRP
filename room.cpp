#include "room.h"
#include "enemy.h"
#include "character.h"
#include "item.h"
#include <string>
#include <list>
#include <algorithm>
using namespace std;
Room::Room(int MonsterType, string RoomName, string RoomDesc)
{
	Monster = Enemy::createEnemy(MonsterType);
	Puzzle = NULL;
	Visited = false;
	Name = RoomName;
	Desc = RoomDesc;
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


Item Room::TakeFrom(string compare)
{
	//How do I do this?
	list<Item>::iterator it;
	it = find(LooseItems.begin(),LooseItems.end(), compare);
	if(it != LooseItems.end())
	{
		Item temp(*it);
		LooseItems.erase(it);
		return temp;
	}
	else
	{
		Item temp("Error","That Item doesn't exist", 0, 0, 0);
		return temp;
	}
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

void DisplayItem(Item it)
{
	cout << it.Name() << " ";
}

void Room::DescribeItems()
{
	for_each(LooseItems.begin(),LooseItems.end(), DisplayItem);
}

int Room::NumItems()
{
	return LooseItems.size();
}
