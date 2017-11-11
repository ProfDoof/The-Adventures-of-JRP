#ifndef ROOM_H
#define ROOM_H
#include "character.h"
#include "enemy.h"
#include "item.h"

class Room{
	private:
		Character* Adventurer;
		Enemy* Monster;//
		Curio* Puzzle;//
		bool Visited;//
		string Name;//
		string Desc;//
		list<Item> LooseItems;//
	public:
		Room();
		Room(int MonsterType, string RoomName, string RoomDesc);

		bool visit() const;
		void visit(bool input);

		string roomname() const;
		void roomname(string input);

		string description() const;
		void description(string desc);

		void AddToFloor(Item ttt);
		Item TakeFrom();

		Curio* LookAtCurio() const;
		void ChangeCurio(Curio* input);

		Enemy* CurrentEnemy() const;
		void ChangeEnemy(Enemy* input);


};
#endif
