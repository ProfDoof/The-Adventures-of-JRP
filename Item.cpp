using namespace std;

void Item::Use(Character* ent)
{
	if(Healing() > 0)
		ent->HP((HP()+Healing()));
	else if(Damage() > 0)
		ent->HP((HP()-Damage()));
	else
		throw Error("This Item can't be used that way!'");
}
