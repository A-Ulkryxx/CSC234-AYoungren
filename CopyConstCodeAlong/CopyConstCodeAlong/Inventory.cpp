#include "Header.h"
using namespace std;

Inventory::Inventory()
{
	
}

//copy constructor
Inventory::Inventory(const Inventory& old)
{
	for (int i = 0; i < this->item1.size(); i++)
	{
		item1[i]= new Item(old.item1[i]);
	}
}

//deconstructor
Inventory::~Inventory()
{
	cleanUp();
}

void Inventory::cleanUp() //Good practive to have a method for deletion that the deconsstructor calls
{
	for (int i = 0; i < this->item1.size(); i++) 
	{
		delete item1[i];
	}
	
}

vector <Item*> Inventory::getItem()
{
	return item1;
}

void Inventory::addItem(Item item)
{
	Item* temp = new Item(item);
	item1.push_back(new Item(temp));
}

void Inventory::addInventory(Inventory inv)
{
	for (Item* i : inv.getItem())
	{
		Item* temp = new Item(i);
		this->getItem().push_back(temp);
	}
}

Inventory Inventory::mergeInventories(Inventory inv)
{
	Inventory temp;
	for (Item* item : item1)
	{
		Item* temp2 = new Item(item);
		temp.item1.push_back(temp2);
	}

	for (Item* item : inv.item1)
	{
		Item* temp2 = new Item(item);
		temp.item1.push_back(temp2);
	}
	return temp;
}

Inventory Inventory::mergeInventories(Item item)
{
	Inventory temp;
	for (Item* item : item1)
	{
		Item* temp2 = new Item(item);
		temp.item1.push_back(temp2);
	}
	Item* temp2 = new Item(item);
	temp.item1.push_back(temp2);
	return temp;
}

void Inventory::copy(Inventory inv)
{
	cleanUp();
	for (Item* item : inv.item1)
	{

	}
}

void Inventory:: operator +=(Item item)
{
	Item* temp = new Item(item);
	item1.push_back(new Item(temp));
}

void Inventory:: operator +=(Inventory inv)
{
	for (Item* i : inv.getItem())
	{
		Item* temp = new Item(i);
		this->getItem().push_back(temp);
	}
}

Inventory Inventory::operator +(Inventory inv)
{
	for (Item* i : inv.getItem())
	{
		Item* temp = new Item(i);
		this->getItem().push_back(temp);
	}
}

Inventory Inventory::operator +(Item item)
{
	Item* temp = new Item(item);
	item1.push_back(new Item(temp));
}

void Inventory::operator =(Inventory inv)
{
	
}

Item* Inventory::operator[](int index)
{
	this->getItem()[index];
}