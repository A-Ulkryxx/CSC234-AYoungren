//This program lets you create, copy, combine containers of items.  If you were in an RPG game this could be the bag you are carrying
//   or the treasure chest of items you find.
//You will need to write copy constructors and overloaded operators.  As you read through the code you will see comments explaining
//   what you need to do.  Have your copies of the PowerPoint available so you can use them as reference.
//The comments that are numbers should be done first and in the order they are listed.  Unnumbered comments can be done in any 
//   order after the first ones are done.
//You need to move the code into multiple files you will end up with 5 files.  CC_OO, item.h, item.cpp, Inventory.h and inventory.cpp.  
//   You may do this at any time.

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Item
{
private:
	string name;

public:
	Item()
	{
		name = "";
	}

	Item(string name)
	{
		this->name = name;
	}
	// Not a Copy Constructor, this is a normal constructor that takes in an item.
	Item(Item* item)
	{
		this->name = item->name;
	}

	//overloaded operator <<.
	friend ostream& operator << (ostream& output, Item obj)
	{
		output << obj.name;
		return output;
	}
	//last:  overload operator >> 
};


class Inventory
{
private:
	vector<Item*> itemList;

public:
	Inventory()
	{

	}
	//*******************************************************************************************************************/
	//1. finish writing the copy constructor
	Inventory(const Inventory& old)
	{
		cout << "in Inventory copy constructor ";
	}

	//destructor
	~Inventory()
	{
		for (Item* item : itemList)
		{
			delete item;
		}
	}

	//*******************************************************************************************************************/
	//2 add overloaded operator for <<. (see example in item);

	//add overloaded operator for =.  (remember the one on the left will only have what is on the right, it isn't a +=)
	//add overloaded operator for +, which adds an item to the inventory, 
	//add overloaded operator for +, which add all of the inventory to another inventory
	//add overloaded operator for += for both adding a single item and a whole inventory.


};


//uncomment the items in main as you get them to work.
int main()
{
	Inventory chest1;
	Inventory chest2;
	Inventory chest3;
	Item* itemName = new Item;
	//chest1 += new Item( "Sword" );
	//chest1 += new Item( "Sheild" );
	//cout << "chest1 " << chest1 << endl;

	//chest3 = chest1;
	//cout << "chest3 " << chest3 << endl;

	//chest2 += new Item( "Armor" );
	//chest2 += new Item( "Potion" );
	//chest2 += new Item( "Dragon Scale" );
	//cout << "chest2 " << chest2 << endl;

	//cout << "Enter the name of an item:  ";
	//cin >> itemName;		//write the overload operator in Item.

	//chest3 = chest1 + itemName;
	//cout << "chest3 again" << chest3 << endl;


	//Inventory playerInv = chest1; 
	//cout << playerInv<<endl;

	//playerInv = playerInv + chest2;
	//cout << playerInv<<endl;
	return 0;
}