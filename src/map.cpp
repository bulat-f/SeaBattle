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
    Hit result = (*parent)[c].hit();
    (*this)[c].hit(result);
    return result;
}
