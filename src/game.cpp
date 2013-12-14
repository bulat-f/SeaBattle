#include "game.h"

#include "coord.h"
#include "hit.h"
#include <iostream>

using namespace std;

Game::Game(const Coord &c): board1(c), board2(c), map1(&board2), map2(&board1),
                            player1(&board1, &map1), player2(&board2, &map2),
                            view1(&board1, &map1), view2(&board2, &map2)
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
    view2.show();
    Coord c;
    Ship::position pos;
    while(!player1.isComplete())
    {
        cin >> c >> pos;
        if (!player1.setShip(c, pos)) cout << "Please, try again\n"; else view1.show();
    }
    while(!player2.isComplete())
    {
        cin >> c >> pos;
        if (!player2.setShip(c, pos)) cout << "Please, try again\n"; else view2.show();
    }
    int i = 0;
    while (i < 5)
    {
        cin >> c;
        cout << player1.hit(c) << endl;
        view1.show();
    }
}
