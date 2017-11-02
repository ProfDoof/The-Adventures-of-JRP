using namespace std;


Item::Item(string Nam, string Desc, int Dam, int Heal)
{
	Name(Nam);
	Description(Desc);
	Damage(Dam);
	Healing(Heal);
}

void Item::Use(Curio* stuff)
{
	
}

void Item::Use(Character* ent)
{
	if(Healing() > 0)
		ent->HP((HP()+Healing()));
	else if(Damage() > 0)
		ent->HP((HP()-Damage()));
	else
		cout << "This item cannot be used in that way." << endl;
}
