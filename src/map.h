#ifndef MAP_H
#define MAP_H

#include "grid.h"

#include "mapelement.h"
#include "hit.h"
#include "board.h"
#include "coord.h"


class Map: public Grid<MapElement>
{
    friend class View;

    public:
        Map(Board *b);
        virtual ~Map();

        Hit hit(const Coord &c);
    protected:
        Board *parent;
    private:
};

#endif // MAP_H
