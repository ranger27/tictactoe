#include <iostream>
#include <string>

// user defined header files
#include "../HeaderFiles/player.h"

using namespace std;

class Board
{
    int row;
    int column;
    
    char matrix[3][3];

public:
    // constructs board
    Board();
    // returns true if successfully put a player's move in a square else false
    bool fillWith(Player&, int);
    bool isGameWon();
};

Board::Board()
{
    cout << "cons called" << endl;
    row = 3;
    column = 3;
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<3;j++){
            // initialize every squares with 0.
            matrix[i][j] = '0';
        }
    }
}

bool Board::fillWith(Player& p, int position){
    if(position > 9 || position < 1){
        cout << "INVALID POSITION. ENTER FROM 1-9."
        return false;
    }

    char & a = matrix[(position-1)/3][(position-1)%3];
    if(a != '0' ){
        // i.e. already occupied
        return false;
    }else{
        a = p.sign;
        return true;
    }
}