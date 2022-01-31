/*Austin Youngren
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    char view;
    ifstream infile;
    string instructions;

    infile.open("shutTheBoxInstructions.txt", ios::in);

    cout << "Would you like to read the directions for \"Shut the Box\"? (y/n)\n";
    cin >> view;
    cout << "\n\n";

    if (view == 'y')
    {
        while (!infile.fail() && getline(infile, instructions))
        {
            cout << instructions << endl;
        }
    }
    else { ; }

    infile.close();

    system("PAUSE");
    return 0;
}
