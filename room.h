#ifndef ROOM_H
#define ROOM_H
#include "character.h"
#include "enemy.h"
#include "item.h"

class Room{
	private:
		Enemy* Monster;//
		Curio* Puzzle;//
		bool Visited;//
		string Name;//
		string Desc;//
		list<Item> LooseItems;//
	public:
		Room();
		Room(int MonsterType, string RoomName, string RoomDesc);
		~Room() {if(Monster) delete Monster; if(Puzzle) delete Puzzle; }

		bool visit() const;
		void visit(bool input);

		string roomname() const;
		void roomname(string input);

		string description() const;
		void description(string desc);

		void AddToFloor(Item ttt);
		Item TakeFrom(string compare);

		Curio* LookAtCurio() const;
		void ChangeCurio(Curio* input);

		Enemy* CurrentEnemy() const;
		void ChangeEnemy(Enemy* input);

		class Error {
			public:
                std::string desc;
				Error(std::string description) : desc(description) {}
		};
};
#endif
