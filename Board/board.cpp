#include <iostream>
#include <string>

// user defined header files
#include "../HeaderFiles/board.h"

using namespace std;

Player &Board::whoWonTheGame(Player &a, Player &b, int row, int column)
{
    if (a.sign == matrix[row][column])
    {
        cout << a.name << " is winner..." << endl;
        return a;
    }
    else  //(b.sign == matrix[row][column])
    {
        cout << b.name << " is winner..." << endl;
        return b;
    }
}

Board::Board()
{
    cout << "cons called" << endl;
    row = 3;
    column = 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // initialize every squares with 0.
            matrix[i][j] = '0';
        }
    }
}

bool Board::fillWith(Player &p, int position)
{
    if (position > 9 || position < 1)
    {
        cout << "INVALID POSITION. ENTER FROM 1-9." << endl;
        return false;
    }

    char &a = matrix[(position - 1) / 3][(position - 1) % 3];
    if (a != '0')
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

void Board::isGameWon(Player &a, Player &b)
{
    if (matrix[0][0] == matrix[1][1] == matrix[2][2] || matrix[0][2] == matrix[1][1] == matrix[2][0])
    {
        whoWonTheGame(a, b, 1, 1);
    }
    //  for horizontal checking
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == matrix[i][1] == matrix[i][2])
        {
            whoWonTheGame(a, b, i, 0);
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

        if (matrix[0][i] == matrix[1][i] == matrix[2][i])
        {
            whoWonTheGame(a, b, 0, i);
        }
    }
}



