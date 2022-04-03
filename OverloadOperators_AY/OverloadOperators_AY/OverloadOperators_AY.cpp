/*Directions:  Go through the code and create the methods required.
You will need to read in a file called people.txt.
The names were randomly generated and as you see them they are not real names.
You may change names and ages or add more names.

This assignment will require you to estimate how long it will take you to do the assignment
one finish write down how long it actually took.
If you are off by more than 10%, write down why you think you were wrong.

recommended:  comment out all of lines in main and add them in and you write code to test it.
You will probably want to add other lines of code to test the code completely.
We will be testing the code with a differnt main.

The final copy needs to work correctly in multiple files.

**********************************************************************************************
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
private:
	string personName;
	int age;
public:
	Person()
	{
		personName = "none";
		age = -1;
	}
	Person(Person* p)
	{
		personName = p->personName;
		age = p->age;
	}
	//optional add constructor with parameters
	//Add copy construcor

	~Person()
	{
	}
	//use this method to see if you code is working.  Remove once you have the overloaded operator << working
	void printPerson()
	{
		cout << "name: " << personName;
		cout << " age: " << age;
	}

	//add overload operator to output a Person
	//add overload operator to input a person
	int getAge()
	{
		return age;
	}
	//optional add other getters and setters

};

class Clan
{
private:
	vector<Person*> memberList;
	string clanName;
public:
	Clan()
	{
		clanName = "none";
	}
	//optional add constructor with parameters
	//add deconstructor

	//Add copy construcor

	//use this method to see if you code is working.  Remove once you have the overloaded operator << working
	void printClan()
	{
		cout << "Clan name: " << clanName;
		for (Person p : memberList)
		{
			p.printPerson();
		}
	}

	//add overload operator to output a Clan, call the overloaded operator for Person
	//add overload operator to input a Clan, call the overloaded operator for Person
	//add overloaded operators to combine two Clans
	//add overloaded operators to add a Person to the Clan

	//These methods return the clan number that is "stronger"; a zero is returned if they are exactly equal.
	//Only called if the two clans are the same size.
	double averagAge()
	{
		double total = 0;
		for (Person* person : memberList)
		{
			total = total + person->getAge();;
		}
		return total / memberList.size();
	}
	int ageCompare(Clan c2)
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


	//add overloaded operators to compare two clans by number of people, if the people are the same compare the ages (already written)

	//optional add getters and setters

};

////put unique information in all variables below so you know it works.
//int main( )
//{
//	Person person1;
//	Person person2;
//	Clan clan1;
//	Clan clan2;
//	Clan bigClan;
//
//	//Open the file and read in 11 people into clan1 and the rest into clan2
//	//since you are passing in the input stream you will be using the overloaded operator >>
//	//		without changing the method.
//
//	cout << "The two empty people:\n";
//	cout << "1" << person1 << "2" << person2;
//	cout << "The two empty clans:\n";
//	cout << clan1 << clan2;
//
//	clan1 = clan1 + person1;
//	clan2 = clan2 + person2;
//	cout << "The two filled clans:\n";
//	cout << clan1 << clan2;
//	bigClan = clan1 + clan2;
//	cout << "the big clan\n";
//	cout << bigClan;
//	if (clan1 > clan2)
//	{
//		clan1 = clan1 + clan2;
//	}
//	else if (clan1 > clan2)
//	{
//		clan2 = clan2 + clan1;
//	}
//
//	cout << "final Clan 1\n";
//	clan1.printClan( );
//	cout << "final Clan 2\n";
//	clan2.printClan( );
//	cout << "final Big Clan\n";
//	bigClan.printClan( );
//}