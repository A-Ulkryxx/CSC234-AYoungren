/*
* Austin Youngren

Directions:  Go through the code and create the methods required.
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

#include "Header.h"
using namespace std;

////put unique information in all variables below so you know it works.
int main( )
{
	Person* person1;
	Person* person2;
	Clan clan1;
	Clan clan2;
	Clan bigClan;
	person1 = new Person("Rahdan", 22);
	person2 = new Person("Godrick", 33);
	//Open the file and read in 11 people into clan1 and the rest into clan2
	//since you are passing in the input stream you will be using the overloaded operator >>
	//		without changing the method.
	ifstream inFile;
	string memberName;
	int memberAge;
	int size;
	int count = 0;

	inFile.open("people.txt");

	if (!inFile.is_open())
	{
		cout << "exit";
	}
	inFile >> size; //the number of names in the file.
	for (int i = 0; i < size && !inFile.fail(); i++)
	{
		person1 = new Person;
		inFile >> person1;

		if (count < 11)
		{
			clan1 = clan1 + person1;
		}
		else
		{
			clan2 = clan2 + person1;
		}
		count++;
	}

	cout << "AFTERLOOP";
	inFile.close();

	clan1.setClanName("Clan 1");
	clan2.setClanName("Clan 2");
	
	cout << "The two empty people:\n";
	cout << "1" << person1 << "2" << person2;
	cout << "The two empty clans:\n";
	cout << clan1 << clan2;

	clan1 = clan1 + person1;
	clan2 = clan2 + person2;
	cout << "The two filled clans:\n";
	cout << clan1 << clan2;
	bigClan = clan1 + clan2;
	bigClan.setClanName("Big Clan");
	cout << "the big clan\n";
	cout << bigClan;
	if (clan1 > clan2)
	{
		clan1 = clan1 + clan2;
	}
	else if (clan1 > clan2)
	{
		clan2 = clan2 + clan1;
	}

	cout << "final Clan 1\n";
	clan1.printClan( );
	cout << "final Clan 2\n";
	clan2.printClan( );
	cout << "final Big Clan\n";
	bigClan.printClan( );
}