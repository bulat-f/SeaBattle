#include "game.h"

#include "coord.h"
#include "hit.h"
#include <iostream>

using namespace std;

Game::Game(const Coord &c): board1(c), board2(c), map1(&board2), map2(&board1),
                            player(&board1, &map1), computer(&board2, &map2),
                            view1(&board1, &map1), view2(&board2, &map2), current(PLAYER)
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
    view1.show();
    Coord c;
    unsigned int pos;
    while(!player.isComplete())
    {
        cin >> c >> pos;
        cout << c;
        if (!player.setShip(c, pos)) cout << "Please, try again\n"; else view1.show();
    }
    computer.assignSquadron();
    Hit result;
    while (!player.isLoser() && !computer.isLoser())
    {
        if (current == PLAYER)
        {
            cin >> c;
            result = player.hit(c);
            view1.show();
            current = (!result.valid() || result.target()) ? PLAYER : COMPUTER;
        }
        else
        {
            result = computer.hit();
            if (result.valid()) cout << "Computer: " << result << endl;
            current = (!result.valid() || result.target()) ? COMPUTER : PLAYER;
        }
    }
}
