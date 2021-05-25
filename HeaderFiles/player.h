#include <string>
#include "board.h"
using namespace std; // for the string to have in this scope

#ifndef PLAYER_FILE_MEMBERS
#define PLAYER_FILE_MEMBERS
class Player
{
    string name;
    char sign;
public:
    Player(string name);
    friend bool Board::fillWith(Player&, int);
};
#endif