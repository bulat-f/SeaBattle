#include "player.h"

#include "coord.h"

Player::Player(Board *bValue, Map *mValue): board(bValue), map(mValue), N(10), types(4)
{
    //ctor
    int counter = 0;
    for (int i = 0; i < types; i++)
    {
        for (int k = 1; k <= i + 1; k++)
        {
            squadron[counter++] = new Ship(types - 1 - i);
        }
    }
}

Player::~Player()
{
    //dtor
    for (int i = 0; i < N; i++)
    {
        delete squadron[i];
    }
}

void Player::setSquadron()
{
    Coord c;
    int i = 0;
    while (i < N)
    {
        cin >> c;
        if (board->setShip(squadron[i], c)) i++; else count << "Please, try again" << endl;
    }
}
