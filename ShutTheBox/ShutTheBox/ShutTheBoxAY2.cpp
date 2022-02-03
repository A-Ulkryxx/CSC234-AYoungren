/*Austin Youngren
* Feb. 2/2022
* Descripton: Shut the box can be played by one to two people. The game contains 9 numbered, open 
* boxes. Players will roll two dice to toggle the boxes that correlate with the numbers rolled
* (as seperate numerals or a combined sum). 
* Example: If a player were to roll a 2 and a 4, they could toggle boxes 2 and 4 or toggle box 6.
* If the box correlating with the rolled number is shut, that box will be opened.
* If a player, in a 2 player game, were to roll the same number on both dice they could toggle that number 
* twice or toggle the added sum, then take another turn.
* The player to shut all boxes on thier turn wins the game.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void openInstructions();
void diceRoll(int& dice1,int& dice2);

int main()
{
    srand((unsigned)time(0));
    char view;
    int dice1, dice2;
    int diceSum = 0, diceChoice;;

    cout << "Would you like to read the directions for \"Shut the Box\"? (y/n)\n";
    cin >> view;
    cout << "\n\n";

    if (view == 'y')
    {
        openInstructions();
    }
    else { ; }

    diceRoll(dice1, dice2);
    cout << "\n\nDice One rolled: " << dice1 << "\nDice Two rolled: " << dice2 << "\n";
    cout << "Would you like to use these dice seperately(1) or as an added sum(2)?\n";
    cin >> diceChoice;
    if (diceChoice == 2)
    {
        diceSum = dice1 + dice2;
        if ((diceSum > 9) && (diceSum < 2))
        {
            cout << "This sum of dice is not within range. You will have to use the dice seperately";
            return dice1, dice2;
        }
        else
        {
            return diceSum;
        }
    }
    else { ; }

    cout << diceSum;
    
    system("PAUSE");
    return 0;
}

void diceRoll(int &dice1,int &dice2)
{
    dice1 = 1 + (rand() % 6);
    dice2 = 1 + (rand() % 6);
}

void openInstructions()
{
    ifstream infile;
    string instructions;

    infile.open("shutTheBoxInstructions.txt", ios::in);

    while (!infile.fail() && getline(infile, instructions))
    {
        cout << instructions << endl;
    }
    infile.close();
}

//Problems: None