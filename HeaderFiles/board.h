
#ifndef BOARD_FILE_MEMBERS
#define BOARD_FILE_MEMBERS
#include "player.h"

class Board
{
    int row;
    int column;
    char matrix[3][3];
    void whoWonTheGame(Player &a, Player &b, int row, int column);

public:
    Board();
    bool fillWith(Player &, int);
    bool isGameWon(Player &a, Player &b);
    bool isGameDraw(Player &a, Player &b); 
    void showCurrentBoard();
};
#endif