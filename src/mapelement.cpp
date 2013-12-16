#include "mapelement.h"

MapElement::MapElement(): parent(NULL), state(WATER)
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
        break;
    case Hit::MISS:
        state = MISS;
        break;
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
