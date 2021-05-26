#include <iostream>
#include <string>
#include "../HeaderFiles/board.h"

using namespace std;

istream & operator >> (istream & din,Player & p){
    cout << "What is your name? "<<endl;
    din >> p.name;
    cout << "What is your preferred sign? ( O or X )"<<endl;
    din >> p.sign;
    return din;
}


