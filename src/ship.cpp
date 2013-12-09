#include "ship.h"

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
    int x = 0, y = 0;
    if (pos == HORIZONTAL) x = 1; else y = 1;
    Coord c(x, y);
    return c;
}
