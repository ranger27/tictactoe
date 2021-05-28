#include <iostream>
#include <string>

// user defined header files
#include "../HeaderFiles/board.h"

using namespace std;

void Board::whoWonTheGame(Player &a, Player &b, int row, int column)
{
    if (a.sign == matrix[row][column])
    {
        // cout << a.name << " is winner..." << endl;
        a.amIWinner = true;
        b.amIWinner = false;
    }
    else //(b.sign == matrix[row][column])
    {
        // cout << b.name << " is winner..." << endl;
        a.amIWinner = false;
        b.amIWinner = true;
    }
}

Board::Board()
{
    // cout << "cons called" << endl;
    row = 3;
    column = 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // initialize every squares with 0.
            matrix[i][j] = 48+ (3*i+j+1);
        }
    }
}

// returns true if a position in square is successfully filled ,false otherwise.
// the first square is 1 not 0 (keep in mind)
bool Board::fillWith(Player &p, int position)
{
    if (position > 9 || position < 1)
    {
        cout << "INVALID POSITION. ENTER FROM 1-9." << endl;
        return false;
    }

    char &a = matrix[(position - 1) / 3][(position - 1) % 3];
    if (a == 'O' || a=='X')
    {
        // i.e. already occupied
        return false;
    }
    else
    {
        a = p.sign;
        return true;
    }
}

// returns true for game win.
bool Board::isGameWon(Player &a, Player &b)
{

    // diagonal checking
    if ((matrix[0][0] == matrix[1][1]) and (matrix[0][0] == matrix[2][2]) || (matrix[0][2] == matrix[1][1]) and (matrix[0][2] == matrix[2][0]))
    {
        whoWonTheGame(a, b, 1, 1);
        return true;
    }
    //  for horizontal checking
    for (int i = 0; i < 3; i++)
    {
        if ((matrix[i][0] == matrix[i][1]) and (matrix[i][1] == matrix[i][2]))
        {
            whoWonTheGame(a, b, i, 0);
            return true;
            // if (a.sign == matrix[i][0])
            // {
            //     cout << a.name << " is winner..." << endl;
            // }
            // else if (b.sign == matrix[i][0])
            // {
            //     cout << b.name << " is winner..." << endl;
            // }
        }
    }
    // for vertical checking
    for (int i = 0; i < 3; i++)
    {

        if ((matrix[0][i] == matrix[1][i]) and (matrix[1][i] == matrix[2][i]))
        {
            whoWonTheGame(a, b, 0, i);
            return true;
        }
    }

    return false;
}
// prints the current board status
void Board::showCurrentBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] != 'O' and matrix[i][j] != 'X')
            {
                if (j != 2)
                {
                    cout << " \t\t|";
                }
                else
                {
                    cout << " \t\t";
                }
            }
            else
            {
                if (j != 2)
                {
                    cout << "\t" << matrix[i][j] << "\t|";
                }
                else
                {
                    cout << "\t" << matrix[i][j] << "\t";
                }
            }
        }
        if (i != 2)
        {
            cout << "\n----------------------------------------------------\n";
        }
        else
        {
            cout << "\n\n";
        }
    }
}
// returns true if game is draw false otherwise.
bool Board::isGameDraw(Player &a, Player &b)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (matrix[i][j] != 'O' and matrix[i][j] != 'X')
            {
                // game not draw case
                return false;
            }
        }
    }
    // from here the case is of all squares filled but game could be won also at last step.
    // so, we need to check for isgamewon case.
    if (isGameWon(a, b))
    {
        // i.e. if game is won then obviously it is not draw.
        return false;
    }
    else
    {
        return true;
    }
}
