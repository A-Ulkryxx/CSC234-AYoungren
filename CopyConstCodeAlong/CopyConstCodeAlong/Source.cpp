#include "Header.h"

using namespace std;



bool checkForItem(Inventory parInv, Item parItem) //Since we are passing in an item object, this will call copy contructor to make a copy
{	
		//for the scope of this methods. After this method is executed and has returned, that copy is deconstructed
	for (int i = 0; i < parInv.getItem().size(); i++)
	{
		if (parInv.getItem()[i]->getName() == parItem.getName())
		{
			return true;
		}
	}
	return false;
}

int main()
{
	Inventory inv1;
	Inventory inv2;
	Inventory inv3;
	Item item1("Sword");
	Item item2("Sheild");
	Item item3("Dagger");
	
	//inv1.addItem(item1);
	inv1 += item1;
	cout<<checkForItem(inv1, item1);
	inv2.addItem(item2);
	inv2.addItem(item3);

	cout << checkForItem(inv1.mergeInventories(inv2), item2) << endl;
	inv1.addInventory(inv2);

	inv3.copy(inv1);
}