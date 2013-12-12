#include "player.h"

#include "coord.h"

Player::Player(Board *bValue, Map *mValue): board(bValue), map(mValue), counter(0)
{
    //ctor
    int iCounter = 0;
    for (int i = 0; i < types; i++)
    {
        for (int k = 1; k <= i + 1; k++)
        {
            squadron[iCounter++] = new Ship(types - i);
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

bool Player::setShip(const Coord &c, Ship::position pos)
{
    squadron[counter]->setPos(pos);
    bool flag = board->setShip(squadron[counter], c);
    if (flag) counter++;
    return flag;
}
