#include <iostream>
#include <string>
#include "../HeaderFiles/board.h"

using namespace std;

class Player
{
    string name;
    char sign;

public:
    Player(string name);
    friend bool Board::fillWith(Player&, int);
};

Player::Player(string name)
{
    this->name = name;
}