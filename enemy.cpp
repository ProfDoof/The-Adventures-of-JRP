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
		return new Byrd(10,100,50,"\“So you’re the one responsible for killing all of my men!\” An older man in an imposing suit of armor yells at you. You recognize him immediately: Duke Byrd! You ready yourself for the confrontation at hand. \“You think you can beat me, whelp?!\” He draws a massive sword and levels it at you. \“You will soon learn to respect your betters!\”","\“Defeated by a… lowly slave…\” Duke Byrd cries as he falls to the ground. His smashes into the golden floor and lies still. He looks up at you, \“How…?\” Finally he notices the sword you’re wielding. \“That sword… curses, I should have known Schubert would get involved…\” Duke Byrd lowers his head and lays still. You have won, your freedom is at hand. Now that you have vanquished Duke Byrd, you are free to roam the castle and look for any items you may have missed. You may use the command ‘exit’ at any time to quit the game.","Duke Byrd II");
	else if(type == 8)
		return new Slave(10,5,10,"\"Lookie what we have here!\" A voice yells at you from across the room. You turn to see a gangly man walking towards you, twitching erratically. \"Now you're gonna give me all those shiny things you've got there, or I'm gonna strip 'em off your corpse.\" He says with a wide smile.","Crazed Slave");
	else if(type == 9)
		return new Rat(2,0,6,"You hear the scurrying of a great number of tiny feet coming from behind you. You turn to see a huge swarm of rats running towards you, and then past you. Confused you turn back around and are met with the sight of an enormous rat crawling towards you out of the darkness. It lets out a mighty squeak and you prepare for battle!","The mighty rat gives one last squeak and finally falls. You have defeated the oversized mutant rat.","Mutated Rat");
	else if(type == 10)
		return new Homer(60,20,70,"A large, burly man turns to face you. He regards you with a look of pure malice and hefts a large axe up onto his shoulder. \“Slave, by entering this room, you’ve popped yourself from the queue of punishment and passed into the loop of agony.\” The eight foot tall mountain of hatred and rage roars and launches himself in your direction!","The giant sinks to his knees. \“The loop of agony… is broken…\” he gasps before collapsing. Somehow, you’ve conquered the beast known as Slave Master Homer.","Slave Master Homer");
	else if(type == 11)
		return new Pettit(100,40,40,"A loud clanking from the corner of the room draws your attention. A man encased in a large suit of metal armor is finishing bolting his helmet onto his cuirass. He draws a sword and raises his shield. \“Any threat to the Duke must be eliminated. You will receive no mercy from me!\”","Pettit drops his sword and shield and slams into the floor, his metal armor making a horrendous noise. You feel that he won’t be bothering you or any other would-be assassins, at least for now.","Royal Guard Pettit");
	else if(type == 12)
		return new Reeves(40,60,60,"A statue rests in the center of the room. You walk past scattered potions and reagents. Movement catches your eye and you watch with horror as the statue rises and looks at you. \“Pitiful slave, dare you gaze upon perfection?\” Alchemist Reeves inquires. \“I’ll add your bones to my collection.\” He snarls and bares his fangs.","\“NO! NOOOOOOOO!\” Reeves cries as his stone form turns to dust and crumbles leaving nothing but a pile of dust on the floor. You breathe a sigh of relief, nobody else will be added to his database of victims.","Court Alchemist Reeves");
	else if(type == 13)
		return new StJohn(50,50,40,"\"By the light of Lord Money I consign thine one soul to the many pits of the inferno.\" A woman wearing cleric's vestments says, striding towards you with a mace held high.","\"Why? Why must I lose?! Was my devotion to Money not great enough?!\" St. John cries as she falls, mace clattering to the floor.","Cleric St. John");
	else if(type == 14)
		return new Tanner(50,50,50,"\"Well, well, well, what have we here. Looks like someone's face needs a little remodeling!\" A rugged man wielding an enourmous hammer says animatedly, stepping towards you.","Tanner drops his hammer to the floor, creating a huge crater where it landed. He falls next to it and goes still. You notice the words \"I love HCI\" are engraved on his hammer. What does that even mean?","Blacksmith Rich Tanner");
	else if(type == 15)
		return new Burton(0,0,0,"","","Engineer Burton");
	
	return NULL;
}
