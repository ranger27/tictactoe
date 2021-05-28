#include <iostream>
#include <string>
#include "../HeaderFiles/player.h"

using namespace std;

Player::Player(char sign)
{
    cout << "Enter your name: \n";
    cin >> name;
    this->sign = sign;
}

void Player::display()
{
    cout << name << " has " << sign << " sign." << endl;
}

string Player::getName()
{
    return name;
}

bool Player::didIWonGame(){
    return amIWinner;
}