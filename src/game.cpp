#include "game.h"

#include "coord.h"
#include "hit.h"
#include <iostream>

using namespace std;

Game::Game(const Coord &c): board1(c), board2(c), map1(&board2), map2(&board1),
                            player(&board1, &map1), computer(&board2, &map2),
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
    while(!player.isComplete())
    {
        cin >> c >> pos;
        if (!player.setShip(c, pos)) cout << "Please, try again\n"; else view1.show();
    }
    computer.assignSquadron();
    view2.show();
    int i = 0;
    while (i < 5)
    {
        cin >> c;
        cout << player.hit(c) << endl;
        view1.show();
    }
}
