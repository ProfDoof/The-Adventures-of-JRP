//this will be a factory
class Enemy: public Character
{
	private:
		//private constructor in the base and derived classes
		string encount;
		string defeat;
	protected:
		Enemy(int hp, int de, int at, string e, string d) : Character(hp, de, at), encount(e), defeat(d) {}
	public:
		//a static method of a class that returns an object of that class type.
		static Enemy* createEnemy(int type);
};

class Guard: public Enemy
{
	friend class Enemy;
	Guard(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Skeleton: public Enemy
{
	friend class Enemy;
	Skeleton(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Slime: public Enemy
{
	friend class Enemy;
	Slime(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Slaver: public Enemy
{
	friend class Enemy;
	Slaver(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Zombie: public Enemy
{
	friend class Enemy;
	Zombie(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Wolf: public Enemy
{
	friend class Enemy;
	Wolf(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Byrd: public Enemy
{
	friend class Enemy;
	Byrd(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Slave: public Enemy
{
	friend class Enemy;
	Slave(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Rat: public Enemy
{
	friend class Enemy;
	Rat(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Pettit: public Enemy
{
	friend class Enemy;
	Pettit(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Reeves: public Enemy
{
	friend class Enemy;
	Reeves(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class StJohn: public Enemy
{
	friend class Enemy;
	StJohn(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};

class Homer: public Enemy
{
	friend class Enemy;
	Homer(int hp, int de, int at, string e, string d) : Enemy(hp,de,at,e,d) {}
};