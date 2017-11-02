Enemy* Enemy::createEnemy(int type)
{
	if(type == 1)
		return new Guard;
	else if(type == 2)
		return new Skeleton;
	else if(type == 3)
		return new Slime;
	else if(type == 4)
		return new Slaver;
	else if(type == 5)
		return new Zombie;
	else if(type == 6)
		return new Wolf;
}	