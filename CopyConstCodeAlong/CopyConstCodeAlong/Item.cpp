#include "Header.h"
using namespace std;

Item::Item()
{

}

Item::Item(string parName)
{
	name = parName;
}

Item::Item(const Item& old)
{
	name = old.name;
}
Item::Item(Item* old)
{
	this->name = old->name;
}

string Item::getName()
{
	return name;
}

void Item::setName(string parName)
{
	name = parName;
}

ostream& operator<<(ostream& output, Item& item)
{
	output << item.name;
}

istream& operator>>(istream& input, Item& item)
{
	input >> item.name;
}