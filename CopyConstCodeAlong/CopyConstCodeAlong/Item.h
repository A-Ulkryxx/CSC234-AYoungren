#pragma once
#include "Header.h"
using namespace std;

class Item
{
private:
	string name;

public:
	Item();
	

	Item(string parName);

	Item(const Item& old);
	
	Item(Item* old);

	string getName();
	
	void setName(string parName);
	
	friend ostream& operator<<(ostream& output, Item& item);

	friend istream& operator>>(istream& input, Item& item);
};

