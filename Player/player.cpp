#include <iostream>
#include <string>
#include "../HeaderFiles/board.h"

using namespace std;

class Player
{
    string name;
    char sign;

public:
    Player(){}
    // input of the player is overloaded
    friend istream & operator >> (istream &,Player &);
    friend bool Board::fillWith(Player&, int);
    friend void Board::isGameWon();
};


istream & operator >> (istream & din,Player & p){
    cout << "What is your name? "<<endl;
    din >> p.name;
    cout << "What is your preferred sign? ( O or X )"<<endl;
    din >> p.sign;
    return din;
}