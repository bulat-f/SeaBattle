#include "boardelement.h"

#include <cstddef>

BoardElement::BoardElement(): parent(NULL), state(WATER)
{
    //ctor
}

BoardElement::~BoardElement()
{
    //dtor
}

HitInfo BoardElement::hit()
{
    switch (state)
    {
    case ALIVE:
        state = DEAD;
        parent->hit();
        if (parent->isAlive())
            return HitInfo::HIT;
        else
            return HitInfo::KILL;
    case MISS:
        return HitInfo::INVALID;
    default:
        state = MISS;
        return HitInfo::MISS;
    }
}

bool BoardElement::setShip(Ship *s)
{
    if (valid())
    {
        parent = s;
        state = ALIVE;
        return true;
    }
    else
        return false;
}

bool BoardElement::valid()
{
    return state == WATER;
}
