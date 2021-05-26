
#ifndef BOARD_FILE_MEMBERS
#define BOARD_FILE_MEMBERS
#include "player.h"

class Board
{
    int row;
    int column;
    char matrix[3][3];
    Player &whoWonTheGame(Player &a, Player &b, int row, int column);

public:
    Board();
    // friend class Player;
    bool fillWith(Player &, int);
    void isGameWon(Player &a, Player &b);
};
#endif