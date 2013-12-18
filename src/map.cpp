#include "map.h"

Map::Map(Board *b): Grid(b->getSize()), parent(b)
{
    //ctor
}

Map::~Map()
{
    //dtor
}

Hit Map::hit(const Coord &c)
{
    if (!valid(c)) return Hit::INVALID;
    Hit result = (*this)[c].valid() ? (*parent)[c].hit() : Hit::INVALID;
    (*this)[c].hit(result);
    if (result.HitInfo == Hit::KILL) this->bordered(c);
    return result;
}
