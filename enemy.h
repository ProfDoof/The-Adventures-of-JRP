//this will be a factory
class Enemy: public Character
{
	private:
		//private constructor in the base and derived classes
		Enemy();
	public:
		//a static method of a class that returns an object of that class type.
		static Enemy* createEnemy(int type);
};

class Guard: public Enemy
{

};

class Skeleton: public Enemy
{

};

class Slime: public Enemy
{

};

class Slaver: public Enemy
{

};

class Zombie: public Enemy
{

};

class Wolf: public Enemy
{

};