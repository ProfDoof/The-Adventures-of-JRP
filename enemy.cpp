#include "enemy.h"
using namespace std;

void Enemy::EnemyName(string input)
{
#ifndef INCLIST
#include <list>
#define INCLIST
#endif
	name = input;
}

string Enemy::EnemyName() const
{
	return name;
}

void Enemy::EncounterLine(string input)
{
	encount = input;
}

string Enemy::EncounterLine() const
{
	return encount;
}

void Enemy::DefeatLine(string input)
{
	defeat = input;
}

string Enemy::DefeatLine() const
{
	return defeat;
}


Enemy* Enemy::createEnemy(int type)
{
	if(type == 0)
		return NULL;
	else if(type == 1)
		return new Guard(50,20,30,"\“What do you think you’re doing up here, slave?\” A voice calls out to you. You turn and see a man in armor striding forward, sword drawn. \“Return to your quarters.\” He snarls.","With a massive metallic clang, the guard crashes to the ground and goes still. Whether he’s dead or just out cold, you’re not sure you want to stick around and find out.","Guard");
	else if(type == 2)
		return new Skeleton(1,1,1,"","","Skeleton");
	else if(type == 3)
		return new Slime(5,30,10,"","","Slime");
	else if(type == 4)
		return new Slaver(30,10,40,"The slaver spots you and cracks his whip, \“Guess you just couldn’t wait for another beating, huh?\” he says, advancing towards you.","\“Curses! How could I lose to filth like you…\” The slaver cries out, collapsing to the ground.","Slaver");
	else if(type == 5)
		return new Zombie(100,0,25,"","","Zombie");
	else if(type == 6)
		return new Wolf(40,15,40,"","","Wolf");
	else if(type == 7)
		return new Byrd(10,100,50,"\“So you’re the one responsible for this mess!\” An older man in an imposing suit of armor yells at you. You recognize him immediately: Duke Byrd! You ready yourself for the confrontation at hand. \“You think you can beat me, whelp?!\” He draws a massive sword and levels it at you. \“You will soon learn to respect your betters!\”","\“Defeated by a… lowly slave…\” Duke Byrd cries as he falls to the ground. His smashes into the golden floor and lies still. He looks up at you, \“How…?\” Finally he notices the sword you’re wielding. \“That sword… curses, I should have known Schubert would get involved…\” Duke Byrd lowers his head and lays still. You have won, your freedom is at hand.","Duke Byrd II");
	else if(type == 8)
		return new Slave(10,5,10,"\"Lookie what we have here!\" A voice yells at you from across the room. You turn to see a gangly man walking towards you, twitching erratically. \"Now you're gonna give me all those shiny things you've got there, or I'm gonna strip \'em off your corpse.\" He says with a wide smile.","Crazed Slave");
	else if(type == 9)
		return new Rat(2,0,6,"You hear the scurrying of a great number of tiny feet coming from behind you. You turn to see a huge swarm of rats running towards you, and then past you. Confused you turn back around and are met with the sight of an enormous rat crawling towards you out of the darkness. It lets out a mighty squeak and you prepare for battle!","The mighty rat gives one last squeak and finally falls. You have defeated the oversized mutant rat.","Mutated Rat");
	else if(type == 10)
		return new Homer(60,20,70,"A large, burly man turns to face you. He regards you with a look of pure malice and hefts a large axe up onto his shoulder. \“Slave, by entering this room, you’ve popped yourself from the queue of punishment and passed into the loop of agony.\” The eight foot tall mountain of hatred and rage roars and launches himself in your direction!","The giant sinks to his knees. \“The loop of agony… is broken…\” he gasps before collapsing. Somehow, you’ve conquered the beast known as Slave Master Homer.","Slave Master Homer");
	else if(type == 11)
		return new Pettit(100,40,40,"","","Royal Guard Pettit");
	else if(type == 12)
		return new Reeves(40,60,60,"","","Court Alchemist Reeves");
	else if(type == 13)
		return new StJohn(50,50,40,"","","Cleric St. John");
	else if(type == 14)
		return new Tanner(0,0,0,"","","Blacksmith Rich Tanner");
	else if(type == 15)
		return new Burton(0,0,0,"","","Engineer Burton");
	
	return NULL;
}
