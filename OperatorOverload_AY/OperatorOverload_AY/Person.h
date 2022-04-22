//Austin Youngren

#pragma once
#include "Header.h"
using namespace std;

/// <summary>
/// Person Object,
/// Person has a name and age
/// </summary>
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
	//optional add constructor with parameters
	Person(string parName, int parAge)
	{
		personName = parName;
		age = parAge;
	}
	Person(Person* p)
	{
		personName = p->personName;
		age = p->age;
	}

	//Add copy construcor
	Person(const Person* p)
	{
		string copyName = p->personName;
		int copyAge = p->age;
		personName = copyName;
		age = copyAge;
	}

	~Person()
	{

	}
	//use this method to see if you code is working.  Remove once you have the overloaded operator << working
	void printPerson();

	//add overload operator to output a Person
	friend ostream& operator << (ostream& output, Person obj)
	{
		output << "Name: " << obj.personName << ", Age: " << obj.age;

		return output;
	}

	//add overload operator to input a person
	friend istream& operator >> (istream& input, Person* obj)
	{
		input >> obj->personName >> obj->age;

		return input;
	}

	int getAge()
	{
		return age;
	}
	//optional add other getters and setters

	void setAge(int parAge)
	{
		this->age = parAge;
	}

	string getPersonName()
	{
		return this->personName;
	}

	void setPersonName(string parPersName)
	{
		this->personName = parPersName;
	}

};
