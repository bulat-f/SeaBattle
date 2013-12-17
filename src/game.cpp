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
    Coord c;
    unsigned int pos;
    while(!player.isComplete())
    {
        cin >> c >> pos;
        if (!player.setShip(c, pos)) cout << "Please, try again\n"; else view1.show();
    }
    computer.assignSquadron();
    bool Queue = true;
    Hit result;
    while (!player.isLoser() && !computer.isLoser())
    {
        if (Queue)
        {
            cin >> c;
            result = player.hit(c);
            view1.show();
            cout << result << endl;
            Queue = !result.valid() || result.target();
        }
        else
        {
            result = computer.hit();
            if (result.valid()) cout << "Computer: " << result << endl;
            Queue = result.valid() || !result.target();
        }
    }
}
