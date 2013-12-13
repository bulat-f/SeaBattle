#include "player.h"

#include "coord.h"

Player::Player(Board *bValue, Map *mValue): board(bValue), map(mValue), counter(0)
{
    //ctor
    for (int i = 0; i < N; i++)
    {
        squadron[i] = new Ship(1);
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

Hit Player::hit(const Coord &c)
{
    return map->hit(c);
}
