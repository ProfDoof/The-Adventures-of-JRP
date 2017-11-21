#include "item.h"
#include <string>
#include <iomanip>
using namespace std;

void quickchange(string& thing)
{
	for(int i = 0; thing[i] != 0; i++)
	{
		thing[i] = tolower(thing[i]);
	}
}

bool Item::operator==(const std::string compare)
{
	string first = compare;
	string second = _Name;
	quickchange(first);
	quickchange(second);
	
	return first == second;
}