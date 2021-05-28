
#ifndef PLAYER_FILE_MEMBERS
#define PLAYER_FILE_MEMBERS

// include error of circular include was solved by forward declaration and friend class

#include <string>

using namespace std; // for the string to have in this scope

class Board; // forward declaration
class Player
{
    string name;
    char sign;
    bool amIWinner=false;

public:
    Player(char sign);
    string getName();
    bool didIWonGame();
    // input of the player is overloaded
    friend class Board;
    // friend bool Board::fillWith(Player &, int);
    // friend void Board::isGameWon(Player &a, Player &b);
    // friend Player & Board::whoWonTheGame(Player &a, Player &b, int row, int column);

    void display();
};

#endif
