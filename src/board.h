#ifndef BOARD_H
#define BOARD_H

#include "grid.h"
#include "coord.h"
#include "boardelement.h"
#include "ship.h"

class Board: public Grid<BoardElement>
{
    friend class View;

    public:
        Board();
        Board(const Coord& value);
        virtual ~Board();
        Coord getSize();
        bool setShip(Ship *p, Coord c);
    protected:
        bool setBorder(const Coord &c);
        bool validForShip(const Ship &p, Coord c);
    private:
};

#endif // BOARD_H
