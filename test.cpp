//test.cpp
#include <iostream>
#ifndef INCITEM
#include "item.h"
#define INCITEM
#endif
#ifndef INCCHARACTER
#include "character.h"
#define INCCHARACTER
#endif
#ifndef INCENEMY
#include "enemy.h"
#define INCENEMY
#endif
#ifndef INCROOM
#include "room.h"
#define INCROOM
#endif
#ifndef INCDUNGEON
#include "dungeon.h"
#define INCDUNGEON
#endif
#ifndef INCGAME
#include "game.h"
#define INCGAME
#endif


//this will be a factory

int main()
{
	Game JPR();
	Dungeon YourMap();
	Room Base(2,"Testing Room", "This rooms only purpose is to have no purpose", 4);
	Enemy* Villains[10];
	Villains[0] = Enemy::createEnemy(1);
	Villains[1] = Enemy::createEnemy(2);
	Villains[2] = Enemy::createEnemy(3);
	Villains[3] = Enemy::createEnemy(4);
	Villains[4] = Enemy::createEnemy(5);
	Villains[5] = Enemy::createEnemy(6);
	Villains[6] = Enemy::createEnemy(7);
	Villains[7] = Enemy::createEnemy(8);
	Villains[8] = Enemy::createEnemy(9);
	Villains[9] = Enemy::createEnemy(10);
	cout << Villains[0]->EnemyName() << endl;
	cout << Villains[1]->EnemyName() << endl;
	cout << Villains[2]->EnemyName() << endl;
	cout << Villains[3]->EnemyName() << endl;
	cout << Villains[4]->EnemyName() << endl;
	cout << Villains[5]->EnemyName() << endl;
	cout << Villains[6]->EnemyName() << endl;
	cout << Villains[7]->EnemyName() << endl;
	cout << Villains[8]->EnemyName() << endl;
	cout << Villains[9]->EnemyName() << endl;
	cout << (Base.CurrentEnemy())->EnemyName() << endl;
	cout << Base.roomname() << endl;
	cout << Base.description() << endl;
	cout << Base.visit() << endl;
	cout << Base.Trap() << endl;
	Character Adventurer(10,10,10);
	Item AKnife("Knife","Can be used for cutting vegetables or can deal 4 damage",4,0);
	cout << AKnife.Name() << endl;
	cout << AKnife.Description() << endl;
	cout << AKnife.Damage() << endl;
	cout << AKnife.Healing() << endl;

	return 0;
}
