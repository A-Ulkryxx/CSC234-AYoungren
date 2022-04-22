//Austin Youngren
#pragma once
#include "Header.h"
using namespace std;

//use this method to see if you code is working.  Remove once you have the overloaded operator << working
void Clan::printClan()
{
	cout << "Clan name: " << clanName << endl;
	for (Person* p : memberList)
	{
		p->printPerson();
	}
}


//add overload operator to input a Clan, call the overloaded operator for Person

void Clan:: operator =(Clan obj)
{
	Person* tempPers;
	for (Person* p : this->memberList)
	{
		delete p;
	}
	this->memberList.clear();

	for (Person* p : obj.memberList)
	{
		tempPers = new Person(p);
		this->memberList.push_back(tempPers);
	}

}
//add overloaded operators to combine two Clans
Clan Clan:: operator +(Clan obj)
{
	Clan tempClan;
	Person* tempPers;
	for (Person* p : this->memberList)
	{
		tempPers = p;
		tempClan.memberList.push_back(new Person(tempPers));
	}

	for (Person* p : obj.memberList)
	{
		tempPers = p;
		tempClan.memberList.push_back(new Person(tempPers));
	}
	return tempClan;
}


//These methods return the clan number that is "stronger"; a zero is returned if they are exactly equal.
//Only called if the two clans are the same size.
double Clan:: averagAge()
{
	double total = 0;
	for (Person* person : memberList)
	{
		total = total + person->getAge();;
	}
	return total / memberList.size();
}
int Clan:: ageCompare(Clan c2)
{
	double aveAge1 = this->averagAge();
	double aveAge2 = c2.averagAge();
	bool young1, young2;  //the average person very young
	bool old1, old2;
	young1 = young2 = false;
	old1 = old2 = false;

	if (aveAge1 == aveAge2)
	{
		return 0;
	}
	if (aveAge1 < 20)
	{
		young1 = true;
	}
	if (aveAge2 < 20)
	{
		young2 = true;
	}
	if (aveAge1 > 50)
	{
		old1 = true;
	}
	if (aveAge2 > 50)
	{
		old2 = true;
	}
	if (aveAge1 > aveAge2 && !young2 && !old2)
	{
		return 1;
	}
	else if (aveAge2 < aveAge1 && !young1 && !old1)
	{
		return 2;
	}
	if (!young2 && !old2)
	{
		return 2;
	}
	if (!young1 && !old1)
	{
		return 1;
	}
	//if it gets here both clans are either too old or too young the closer to the limits
	double difArray[4]; //differences for the 4 numbers
	difArray[0] = 20 - aveAge1;
	difArray[1] = aveAge1 - 50;

	difArray[2] = 20 - aveAge2;
	difArray[3] = aveAge2 - 50;
	int low = 0;
	for (int i = 1; i < 4; i++)
	{
		if (difArray[i] < difArray[low])
		{
			low = i;
		}
	}
	return (low / 2 + 1);
}
