
#pragma once
#include "Header.h"

using namespace std;

class Inventory
{
private:
	vector <Item*> item1;
public:
	Inventory();

	//copy constructor
	Inventory(const Inventory& old);

	//deconstructor
	~Inventory();

	void cleanUp(); //Good practive to have a method for delettion that the decontructor calls

	vector <Item*> getItem();
	
	void addItem(Item item);

	void addInventory(Inventory inv);

	Inventory mergeInventories(Inventory inv);

	Inventory mergeInventories(Item item);

	void copy(Inventory inv);

	void operator +=(Item item);

	void operator +=(Inventory inv);

	Inventory operator +(Inventory inv);

	Inventory operator +(Item item);

	void operator =(Inventory inv);

	Item* operator[](int index);
	

};

