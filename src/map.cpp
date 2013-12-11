#include "map.h"

Map::Map(Board *b): Grid(b->getSize()), parent(b)
{
    //ctor
}

Map::~Map()
{
    //dtor
}

void Map::hit(const Coord &c)
{
    Hit res = (*parent)[c].hit();
    (*this)[c].hit(res);
}
