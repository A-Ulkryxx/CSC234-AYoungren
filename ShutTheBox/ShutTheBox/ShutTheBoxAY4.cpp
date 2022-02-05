/*Austin Youngren
* Feb. 7/2022
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

const int BOX_NUMS = 9;

void openInstructions();
void diceRoll(int& dice1,int& dice2);
void getBoxes(int boxes[]);
void toggleStart(string toggle[]);
void gameBoard(const int boxes[], string toggle[]);
void toggleSum(int diceChoice, string toggle[]);
void toggleDice(int dice1, int dice2, string toggle[]);
bool gameWinner(string toggle[]);

int main()
{
    srand((unsigned)time(0));
    char view;
    int dice1, dice2;
    int diceChoice, diceSum;
    int players, playing = 1, winner;
    const int boxes[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    string toggle1[BOX_NUMS], toggle2[BOX_NUMS];
    bool winGame;
    int diceCount1 = 0, diceCount2 = 0;

    cout << "Would you like to read the directions for \"Shut the Box\"? (y/n)\n";
    cin >> view;
    cout << endl;

    if (view == 'y')
    {
        openInstructions();
    }
    else { ; }
    
    do{
        cout << "\n1 player or 2 players?"<<endl;
        cin >> players;
        cout << endl;
    } while ((players < 1) | (players > 2));

    toggleStart(toggle1);
    if (players == 2)
    {
        toggleStart(toggle2);
    }

    do {
        if (playing == 1)
        {
            cout << "Player 1: Before Decision\n";
            gameBoard(boxes, toggle1);
            diceRoll(dice1, dice2);
            diceCount1++;
            cout << "\nDice One rolled: " << dice1 << "\nDice Two rolled: " << dice2 << endl;
            cout << "Would you like to use these dice seperately(1) or as an added sum(2)? \n";
            cin >> diceChoice;

            while ((diceChoice < 1) | (diceChoice > 2))
            {
                cout << "That is not a valid choice, please choose \"seperately\" with \"1\" or \"sum\" with \"2\".\n";
                cin >> diceChoice;
            }

            if (diceChoice == 2)
            {
                diceSum = dice1 + dice2;
                if (diceSum > 9)
                {
                    cout << "This sum of dice is not within range. No move will be taken.\nTurn passed.\n";
                   
                }
                else
                {
                    cout << "Box " << diceSum << " will be toggled\n";
                    toggleSum(diceSum, toggle1);
                }
            }
            else
            {
                cout << "Boxes " << dice1 << " and " << dice2 << " will be toggled\n";
                toggleDice(dice1, dice2, toggle1);
            }
            cout << "\nPlayer 1: After Decision\n";
            gameBoard(boxes, toggle1);
        }
        else
        {
            cout << "Player 2: Before Decision\n";
            gameBoard(boxes, toggle2);
            diceRoll(dice1, dice2);
            diceCount2++;
            cout << "\nDice One rolled: " << dice1 << "\nDice Two rolled: " << dice2 << endl;
            cout << "Would you like to use these dice seperately(1) or as an added sum(2)? \n";
            cin >> diceChoice;

            while ((diceChoice < 1) | (diceChoice > 2))
            {
                cout << "That is not a valid choice, please choose \"seperately\" with \"1\" or \"sum\" with \"2\".\n";
                cin >> diceChoice;
            }

            if (diceChoice == 2)
            {
                diceSum = dice1 + dice2;
                if (diceSum > 9)
                {
                    cout << "This sum of dice is not within range. You will have to use the dice seperately\n";
                    cout << "Boxes " << dice1 << " and " << dice2 << " will be toggled\n";
                    toggleDice(dice1, dice2, toggle2);
                }
                else
                {
                    cout << "Box " << diceSum << " will be toggled\n";
                    toggleSum(diceSum, toggle2);
                }
            }
            else
            {
                cout << "Boxes " << dice1 << " and " << dice2 << " will be toggled\n";
                toggleDice(dice1, dice2, toggle2);
            }
            cout << "\nPlayer 2: After Decision\n";
            gameBoard(boxes, toggle2);
        }

        if (playing == 1)
        {
            winGame = gameWinner(toggle1);
            winner = 1;
        }
        else
        {
            winGame = gameWinner(toggle2);
            winner = 2;
        }
        if ((players == 2) & (dice1 != dice2))
        {
            if (playing == 1)
            {
                playing = 2;
            }
            else
            {
                playing = 1;
            }
        }

    } while (winGame == false);

    cout << "\nPlayer " << winner << " wins!!!";
    cout << "\nPlayer 1 rolled the dice " << diceCount1 << "times.";
    if (players == 2)
    {
        cout << "\nPlayer 2 rolled the dice " << diceCount2 << "times.";
    }
    cout << "\nTotal rolls it took to win the game was " << (diceCount1 + diceCount2);

    system("PAUSE");
    return 0;
}

/// <summary>
/// The rolling of 2 six sided dice
/// </summary>
/// <param name="dice1"> The first die </param>
/// <param name="dice2"> The second die </param>
void diceRoll(int &dice1,int &dice2)
{
    dice1 = 1 + (rand() % 6);
    dice2 = 1 + (rand() % 6);
}

/// <summary>
/// Opens the file to allow the user to read the game instructions
/// </summary>
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
/// <summary>
/// The game board. Displays each box and their current togglt status
/// </summary>
/// <param name="boxes"> Each box's respective number </param>
/// <param name="toggle"> The toggle status of each box </param>
void gameBoard(const int boxes[], string toggle[])
{
    cout << "      " << toggle[0] << "    " << toggle[1] << "    " << toggle[2] << "    " << toggle[3]<< "\n";
    cout << "    _________________________________________\n";
    cout << "    |         |         |         |         |\n";
    cout << "    |    " << boxes[0] << "    " << "|    " << boxes[1] << "    " << "|    " << boxes[2] 
            << "    " << "|    " << boxes[3] << "    |\n";
    cout << "    |         |         |         |         |\n";
    cout << "    |=======================================|\n";
    cout << endl;

    cout << "      " << toggle[4] << "    " << toggle[5] << "    " << toggle[6] 
             << "    " << toggle[7] << "    " << toggle[8] << "\n";
    cout << "    ___________________________________________________\n";
    cout << "    |         |         |         |         |         |\n";
    cout << "    |    " << boxes[4] << "    " << "|    " << boxes[5] << "    " << "|    " << boxes[6] 
            << "    " << "|    " << boxes[7] << "    |" << "    " << boxes[8] << "    |\n";
    cout << "    |         |         |         |         |         |\n";
    cout << "    |=================================================|\n";
    cout << endl;
}   

/// <summary>
/// Sets the toggle status for each box at the beginning of the game to "OPEN"
/// </summary>
/// <param name="toggle"> The toggle status of each box </param>
void toggleStart(string toggle[])
{
    for (int i = 0; i < BOX_NUMS; i++)
    {
        toggle[i] = "*OPEN*";
    }
}

/// <summary>
/// Toggles the box number status that correlates with the sum of two dice
/// </summary>
/// <param name="diceSum"> the total value of two dice added </param>
/// <param name="toggle"> The toggle status of each box </param>
void toggleSum(int diceSum, string toggle[])
{
    if (toggle[diceSum - 1].compare("*OPEN*") == 0)
    {
        toggle[diceSum - 1] = "*SHUT*";
    }
    else
    {
        toggle[diceSum - 1] = "*OPEN*";
    }
}

/// <summary>
/// Toggles two boxes whose numbers correlate with each dice
/// </summary>
/// <param name="dice1"> The first die </param>
/// <param name="dice2"> The second die </param>
/// <param name="toggle"> The toggle status of each box </param>
void toggleDice(int dice1, int dice2, string toggle[])
{
    if (toggle[dice1 - 1].compare("*OPEN*") == 0)
    {
        toggle[dice1 - 1] = "*SHUT*";
    }
    else
    {
        toggle[dice1 - 1] = "*OPEN*";
    }

    if (toggle[dice2 - 1].compare("*OPEN*") == 0)
    {
        toggle[dice2 - 1] = "*SHUT*";
    }
    else
    {
        toggle[dice2 - 1] = "*OPEN*";
    }
}

/// <summary>
/// Traverses a players toggle array to check for a winner.
/// If any boxes are OPEN, function will return false.
/// </summary>
/// <param name="toggle"> The toggle status of each box </param>
/// <returns> false: if any boxes are open.
/// true: if all boxes are shut. </returns>
bool gameWinner(string toggle[])
{
    for (int i = 0; i < BOX_NUMS; i++)
    {
        if (toggle[i].compare("*OPEN*") == 0)
        {
            return false;
        }
    }
    return true;
}



//Problems: None