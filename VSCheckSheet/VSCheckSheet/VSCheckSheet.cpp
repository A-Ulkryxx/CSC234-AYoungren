#include <iostream>
using namespace std;
#include <iomanip>

int main()
{
	cout << setiosflags(ios::fixed) << setprecision(5);

	int integer;
	double doub;
	char character;
	string str1;
	string str2;

	cout << "enter a small number.\n";
	cin >> integer;
	cout << "enter a large number.\n";
	cin >> doub;
	cout << setw(12) << integer << "\n";
	cout << setw(12) << doub << "\n";

	cout << "Would you like to compare two words? (y/n)\n";
	cin >> character;

	

	while (character == 'y')
	{
		cout << "enter a word.\n";
		cin >> str1;
		cout << "enter another word.\n";
		cin >> str2;

		if (str1.at(0) < str2.at(0))
		{
			cout << "\"" << str1 << "\" is before " << "\"" << str2 << "\" when in alphabetic order.\n";
		}
		else if(str1.at(0) > str2.at(0))
		{
			cout << "\"" << str2 << "\" is before " << "\"" << str1 << "\" when in alphabetic order.\n";
		}
		else
		{
			if (str1.at(1) < str2.at(1))
			{
				cout << "\"" << str1 << "\" is before " << "\"" << str2 << "\" when in alphabetic order.\n";
			}
			else if (str1.at(1) > str2.at(1))
			{
				cout << "\"" << str2 << "\" is before " << "\"" << str1 << "\" when in alphabetic order.\n";
			}
			else
			{
				cout << "both \"" << str1 << "\" and \"" << str2 << "\" are the same.\n";
			}
		}

		cout << "Would you like to compare two more words? (y/n)\n";
		cin >> character;
	}

	cout << endl;
	system("pause ");
	return 0;
}

//Problems: 