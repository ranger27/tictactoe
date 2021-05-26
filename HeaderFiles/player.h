
#ifndef PLAYER_FILE_MEMBERS
#define PLAYER_FILE_MEMBERS
#include "board.h"
#include <string>

using namespace std; // for the string to have in this scope

class Player
{
    string name;
    char sign;

public:
    Player() {}
    // input of the player is overloaded
    friend istream &operator>>(istream &, Player &);
    friend bool Board::fillWith(Player &, int);
    friend void Board::isGameWon();
};
#endif