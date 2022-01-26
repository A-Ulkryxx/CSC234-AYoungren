/*Austin Youngren
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int sum = 0;
    int x;
    char view;
    string line;
    ifstream instructions;

    cout << "Would you like to read the directions for \"Shut the Box\"? (y/n)\n";
    cin >> view;
    cout << "\n\n";

    if (view == 'y')
    {
        instructions.open("shutTheBoxInstructions.txt", ios::in);
        if (instructions.is_open()) {
            while (getline(instructions, line)) {
                cout << line << std::endl;
            }
            instructions.close();
        }
        else if (!instructions)
        {
            cout << "Unable to open file.";
            exit(1);
        }
        else { ; }
        
    }
    else { ; }
}
