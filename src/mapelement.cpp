#include "mapelement.h"

MapElement::MapElement(): Element(), state(WATER)
{
    //ctor
}

MapElement::~MapElement()
{
    //dtor
}

void MapElement::hit(Hit result)
{
    switch (result.HitInfo)
    {
    case Hit::HIT:
    case Hit::KILL:
        state = DEAD;
        parent = result.destroyed;
        return;
    case Hit::MISS:
        state = MISS;
        return;
    case Hit::INVALID:
        return;
    }
}

bool MapElement::valid()
{
    return state == WATER;
}

bool MapElement::setBorder()
{
    if (valid())
    {
        state = BORDER;
        return true;
    }
    else
        return false;
}
