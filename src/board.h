#ifndef BOARD_H
#define BOARD_H

#include "grid.h"
#include "coord.h"
#include "boardelement.h"
#include "ship.h"

class Board: public Grid<BoardElement>
{
    public:
        Board();
        Board(const Coord& value);
        virtual ~Board();
        Coord getSize();
        bool setShip(Ship &p, Coord c);
        bool setBorder(const Coord &c);
    protected:
        bool validForShip(const Ship &p, Coord c);

        friend class Viewer;
    private:
};

#endif // BOARD_H
