// Austin Youngren (name)
// 1/28/2022
// Takes two prices then calculates the discount to be applied, than presents the total cost of both items.(description)
//convert the program doubleo 3 functions.  At least two functions have pass by reference.
//Turn in a prdouble out at the end of class
//
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void getPrices(double& price1, double& price2);
void calculateDiscount(double& price1, double& price2);
double calculateTotal(double price1, double price2);
void outputPrices(double price1, double price2);


int main()
{
	cout << setiosflags(ios::fixed) << setprecision(2);

	double price1, price2;
	double total;
	cout << "starting program\n";
	getPrices(price1, price2);
	calculateDiscount(price1, price2);
	outputPrices(price1, price2);

	total = calculateTotal(price1, price2);
	cout << "the total is " << total;
	cout << "\ndone ";
	system("PAUSE");
	return 0;
}
/// <summary>
/// add up the two prices
/// </summary>
/// <param name="price1:">cost of first item</param>
/// <param name="price2:">cost of second item</param>
void getPrices(double& price1, double& price2)
{
	cout << "please enter the price for the item: ";
	cin >> price1;
	cout << "please enter the price for the item: ";
	cin >> price2;
	outputPrices(price1, price2);
}

/// <summary>
/// add up the two prices
/// </summary>
/// <param name="price1:">cost of first item</param>
/// <param name="price2:">cost of second item</param>
void calculateDiscount(double& price1, double& price2)
{
	if (price1 < price2)
	{
		cout << "You get a discount on the most expensive item" << endl;
		price2 = double(price2 * 0.80);
		//price2 = double( price2 - (price2 * 0.20)
	}
	else
	{
		cout << "You get a discount on the most expensive item" << endl;
		price1 = double(price1 * 0.80);

	}
	outputPrices(price1, price2);
}

/// <summary>
/// add up the two prices
/// </summary>
/// <param name="price1:">cost of first item</param>
/// <param name="price2:">cost of second item</param>
/// <returns>total of the two prices</returns>
double calculateTotal(double price1, double price2)
{
	double total;
	total = price1 + price2;
	return total;
}

/// <summary>
/// add up the two prices
/// </summary>
/// <param name="price1:">cost of first item</param>
/// <param name="price2:">cost of second item</param>
void outputPrices(double price1, double price2)
{
	cout << "\ntest price 1: " << price1 << "\ntest price 2: " << price2 << "\n";
}

// Problems ---- 
// Solved:
// TODO: