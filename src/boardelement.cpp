#include "boardelement.h"

#include <cstddef>

BoardElement::BoardElement(): Element(), state(WATER)
{
    //ctor
}

BoardElement::~BoardElement()
{
    //dtor
}

Hit BoardElement::hit()
{
    Hit result;
    switch (state)
    {
    case ALIVE:
        state = DEAD;
        parent->hit();
        result.destroyed = parent;
        if (parent->isAlive())
        {
            result.HitInfo = Hit::HIT;
            return result;
        }
        else
        {
            result.HitInfo = Hit::KILL;
            return result;
        }
    case MISS:
    case DEAD:
        result.HitInfo = Hit::INVALID;
        return result;
    default:
        state = MISS;
        result.HitInfo = Hit::MISS;
        return result;
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

bool BoardElement::setBorder()
{
    if (valid())
    {
        state = BORDER;
        return true;
    }
    else
        return false;
}

bool BoardElement::valid()
{
    return state == WATER;
}
