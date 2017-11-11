//test.cpp
#include <iostream>
#include <list>
#include "Item.h"
#include "Item.cpp"
#include "character.h"
#include "character.cpp"
#include "enemy.h"
#include "enemy.cpp"
#include "game.h"
#include "game.cpp"

//this will be a factory


int main()
{
	Game JPR();
	Item knife("Knife", "Deals 4 damage to enemies", 4, 0);
	cout << knife.Damage() << endl;
	cout << knife.Name() << endl;
	cout << knife.Description() << endl;
	cout << knife.Healing() << endl;
	Character person(100, 100, 100);
	Character food(10,10,10);
	Character* test;
	test = Enemy::createEnemy(1);
	cout << test->ATK() << endl;
	cout << test->DEF() << endl;
	cout << test->HP() << endl;
	cout << food.ATK() << endl;
	cout << food.DEF() << endl;
	cout << food.HP() << endl;
	return 0;
}