#include "element.h"
#include "coord.h"
#include "hit.h"

Element::Element()
{
    //ctor
}

Element::~Element()
{
    //dtor
}

HitInfo Element::hit()
{
    switch (state)
    {
    case ALIVE:
        state = DEAD;
        parent->hit();
        if (parent->isAlive())
            return HitInfo::KILL;
        else
            return HitInfo::HIT;
    case WATER:
        state = MISS;
        return HitInfo::MISS;
    default:
        return HitInfo::INVALID;
    }
}

bool Element::setShip(Ship *s)
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

bool Element::valid()
{
    return state == WATER;
}
