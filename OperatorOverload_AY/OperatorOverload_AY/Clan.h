// Austin Youngren

#pragma once
#include "Header.h"
using namespace std;

/// <summary>
/// Clan Object,
/// A clan contains a vector of people
/// and a clan name.
/// </summary>
class Clan
{
private:
	int tester;
	vector <Person*> memberList;
	string clanName;
public:
	Clan()
	{
		clanName = "none";
	}
	//optional add constructor with parameters
	Clan(string parClanName)
	{
		clanName = parClanName;
	}
	Clan(string parClanName, vector<Person*> parMembers)
	{
		Person* temp;
		clanName = parClanName;
		for (Person* p : parMembers)
		{
			temp = p;
			this->memberList.push_back(new Person(p));
		}
		parMembers.clear();
	}
	//add deconstructor
	~Clan()
	{
		for (Person* p : memberList)
		{
			delete p;
		}
	}

	//Add copy construcor
	Clan(const Clan& origClan)
	{
		Person* tempPers;
		string tempName = origClan.clanName;
		clanName = tempName;
		for (Person* p : origClan.memberList)
		{
			tempPers = new Person(p);
			this->memberList.push_back(tempPers);
		}

	}

	//use this method to see if you code is working.  Remove once you have the overloaded operator << working
	void printClan();
	

	//add overload operator to output a Clan, call the overloaded operator for Person
	friend ostream& operator << (ostream& output, Clan obj)
	{
		output << "Clan Name: " << obj.clanName << endl;
		for (Person* p : obj.memberList)
		{
			output << *p << endl;
		}
		return output;
	}

	//add overload operator to input a Clan, call the overloaded operator for Person

	void operator =(Clan obj);
	
	//add overloaded operators to combine two Clans
	Clan operator +(Clan obj);
	

	//add overloaded operators to add a Person to the Clan
	//add overloaded operators to add a Person to the Clan
	Clan operator + (Person* newMember)				//I cannot figure out what the issue is here
	{
		Clan tempClan;
		Person* tempPers;

		for (Person* p : this->memberList)
		{
			tempPers = new Person(p);
			tempClan.memberList.push_back(tempPers);
		}
		tempPers = new Person(newMember);
		tempClan.memberList.push_back(tempPers);

		return tempClan;
	}
	

	//These methods return the clan number that is "stronger"; a zero is returned if they are exactly equal.
	//Only called if the two clans are the same size.
	double averagAge();
	
	int ageCompare(Clan c2);

	//add overloaded operators to compare two clans by number of people, if the people are the same compare the ages (already written)

	friend bool operator > (Clan callClan, Clan argClan)
	{

		if (callClan.memberList.size() > argClan.memberList.size())
		{
			return true;
		}
		else if (callClan.memberList.size() < argClan.memberList.size())
		{
			return false;
		}
		else
		{
			int ageCompVar = callClan.ageCompare(argClan);
			if (ageCompVar == 2)
			{
				return false;
			}
			else if (ageCompVar == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	//optional add getters and setters: No setter for memberList, unnecessary
	vector<Person*> getMemberList()
	{
		return this->memberList;
	}

	string getClanNAme()
	{

		return this->clanName;
	}

	void setClanName(string parClanName)
	{
		this->clanName = parClanName;
	}
};
