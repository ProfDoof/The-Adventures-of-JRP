#include "item.h"
#include <string>
using namespace std;

bool Item::operator==(const std::string compare)
{
	return _Name == compare;
}