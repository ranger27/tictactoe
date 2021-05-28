#include <iostream>
#include <string>
#include "./HeaderFiles/board.h"
#include "./HeaderFiles/player.h"
using namespace std;

int main()
{
    Board game;
    cout << "=========Game Start========" << endl;
    cout << "You should type of two players." << endl;
    Player p1 = Player('O');
    p1.display();
    Player p2 = Player('X');
    p2.display();
    game.showCurrentBoard();

    int position;
    while (!game.isGameWon(p1, p2) and !game.isGameDraw(p1, p2))
    {
        do
        {
            cout << "Pick your position from (1-9)." << endl;
            cout << p1.getName() << "'s turn: " << endl;
            cin >> position;
            if (game.fillWith(p1, position))
            {
                break;
            };
        } while (true);

        game.showCurrentBoard();

        if (!game.isGameWon(p1, p2) and !game.isGameDraw(p1, p2))
        {
            do
            {
                cout << "Pick your position from (1-9)." << endl;
                cout << p2.getName() << "'s turn: " << endl;
                cin >> position;
                if (game.fillWith(p2, position))
                {
                    break;
                };
            } while (true);
        }
        else
        {
            break;
        }
        game.showCurrentBoard();
    }
    // game won or draw case if code flow is here.
    if (game.isGameDraw(p1, p2))
    {
        cout << "Game is draw......" << endl;
    }
    else if (p1.didIWonGame())
    {
        cout << p1.getName() << " is Winner..." << endl;
    }
    else if (p2.didIWonGame())
    {
        cout << p2.getName() << " is Winner..." << endl;
    }
    return 0;
}
