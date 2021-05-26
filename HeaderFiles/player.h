
#ifndef PLAYER_FILE_MEMBERS
#define PLAYER_FILE_MEMBERS

#include <string>

using namespace std; // for the string to have in this scope

class Board; // forward declaration
class Player
{
    string name;
    char sign;

public:
    Player() {}

    // input of the player is overloaded
    friend istream &operator>>(istream &, Player &);
    friend class Board;
    // friend bool Board::fillWith(Player &, int);
    // friend void Board::isGameWon(Player &a, Player &b);
    // friend Player & Board::whoWonTheGame(Player &a, Player &b, int row, int column);
};
#endif