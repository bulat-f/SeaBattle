#include "ship.h"

#include <iostream>

using namespace std;

Ship::Ship(unsigned char life_value, position pos_value): life(life_value), pos(pos_value)
{
    //ctor
}

Ship::~Ship()
{
    //dtor
}

void Ship::hit()
{
    if (isAlive())
    {
        life--;
    }
}

bool Ship::isAlive() const
{
    return life > 0;
}

unsigned char Ship::getSize() const
{
    return life;
}

Coord Ship::getInc() const
{
    Coord c(0, 0);
    if (pos == HORIZONTAL) c.x = 1; else c.y = 1;
    return c;
}

istream &operator>> (istream &in, Ship::position &pos)
{
    int tmp;
    in >> tmp;
    pos = (tmp == 0 ? Ship::HORIZONTAL : Ship::VERTICAL);
    return in;
}
