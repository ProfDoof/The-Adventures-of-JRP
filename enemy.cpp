void Enemy::EnemyName(string input)
{
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
<<<<<<< HEAD
	if(type == 0)
		return NULL;
	else if(type == 1)
=======
	if(type == 1)
>>>>>>> 9e60df95fb3c2dbac6548d9ab23a2e8a823cd308
		return new Guard(50,20,30,"","","Guard");
	else if(type == 2)
		return new Skeleton(1,1,1,"","","Skeleton");
	else if(type == 3)
		return new Slime(5,30,10,"","","Slime");
	else if(type == 4)
		return new Slaver(30,10,40,"","","Slaver");
	else if(type == 5)
		return new Zombie(100,0,25,"","","Zombie");
	else if(type == 6)
		return new Wolf(40,15,40,"","","Wolf");
	else if(type == 7)
		return new Byrd(10,100,50,"","","Duke Byrd II");
	else if(type == 8)
		return new Slave(10,5,10,"","","Common Slave");
	else if(type == 9)
		return new Rat(2,0,6,"","","Mutated Rat");
	else if(type == 10)
		return new Homer(60,20,70,"","","Slave Driver Homer");
	else if(type == 11)
		return new Pettit(100,40,40,"","","Royal Guard Pettit");
	else if(type == 12)
		return new Reeves(40,60,60,"","","Court Alchemist Reeves");
	else if(type == 13)
		return new StJohn(50,50,40,"","","Cleric St. John");
<<<<<<< HEAD
	
	return NULL;
=======
>>>>>>> 9e60df95fb3c2dbac6548d9ab23a2e8a823cd308
}
