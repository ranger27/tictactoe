#include "player.h"
#ifndef BOARD_FILE_MEMBERS
#define BOARD_FILE_MEMBERS
class Board
{
    int row;
    int column;
    // array of pointers to store each squares.
    int *matrix[3];

public:
    // constructs board
    Board();
    bool fillWith(Player &, int);
    bool isGameWon();
};
#endif