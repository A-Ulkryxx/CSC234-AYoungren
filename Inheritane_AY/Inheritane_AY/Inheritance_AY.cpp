#include <iostream>
#include <vector>
using namespace std;

class SuperClass
{
protected:
	int x;
	int y;
public:
	SuperClass()
	{
		x = 100;
		y = 101;
	}

	int addNumbers()
	{
		return x + y;
	}
	void printNumbers()
	{
		cout << "\nSuperClass: " << x << " " << y;
	}
};
/**************************************************************/
class derivedClass1 : public SuperClass
{
private:
	int x;
	int y;
public:
	derivedClass1()
	{
		x = 10;
		y = 11;
	}

	int addNumbers()
	{
		return x + y;
	}
	virtual void printNumbers()
	{
		cout << "\nderivedClass1: " << x << " " << y << " SuperClass in b1: " << SuperClass::x << " " << SuperClass::y;
	}
};
/**************************************************************/
class derivedClass2 : public SuperClass
{
private:
	int x;
	int y;
public:
	derivedClass2()
	{
		x = 50;
		y = 55;
	}

	int addNumbers()
	{
		return x + y;
	}
	void printNumbers()
	{
		cout << "\nderivedClass2: " << x << " " << y << " SuperClass in b2: " << SuperClass::x << " " << SuperClass::y;
	}
	void setX(int x)
	{
		this->x = x;
	}
};

void funX(int x);
/**************************************************************/
int main()
{
	derivedClass1 *b1 = new derivedClass1;
	derivedClass2 b2;
	SuperClass s1;

	funX(8);
	int* v;
	v = new int;
	vector <SuperClass*> values;
	derivedClass1* obj = new derivedClass1;
	values.push_back( b1 );
	values.push_back(obj);

	for (SuperClass* w: values)
	{
		w->printNumbers();
	}

	b1->printNumbers();
	b2.printNumbers();
	s1.printNumbers();

	delete b1;
	delete obj;
}

void funX(int x)
{
	cout << "Does this work?";
}