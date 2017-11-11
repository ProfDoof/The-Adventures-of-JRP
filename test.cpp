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
	Character person(100, 100, 100);
	Character food(10,10,10);
	Character* test;
	test = Enemy::createEnemy(1);
	cout << test->ATK();
	cout << test->DEF();
	cout << test->HP();
	cout << food.ATK();
	cout << food.DEF();
	cout << food.HP();
	return 0;
}