#include "ship.h"

Ship::Ship(unsigned char life_value, position pos_value): life(live_value), pos(pos_value)
{
    //ctor
}

Ship::~Ship()
{
    //dtor
}

void Ship::hit()
{
    if (isAlive)
    {
        life--;
    }
}

bool Ship::isAlive()
{
    return life > 0;
}
