#include "board.h"

Board::Board(): Grid()
{
    //ctor
}

Board::Board(const Coord& value): Grid(value)
{
    //ctor
}

Board::~Board()
{
    //dtor
}

Coord Board::getSize()
{
    return size;
}

bool Board::setShip(Ship *p, Coord c)
{
    if (!validForShip(*p, c)) return false;
    unsigned char n = p->getSize();
    Coord tmp, border, inc = p->getInc();
    border = inc.invert();

    //
    setBorder(c - inc);
    setBorder(c - inc + border);
    setBorder(c - inc - border);
    //

    for (int i = 0; i < n; i++)
    {
        (*this)[c].setShip(p);
        setBorder(c + border);
        setBorder(c - border);
        c += inc;
    }
    setBorder(c);
    setBorder(c + border);
    setBorder(c - border);
    return true;
}

bool Board::setBorder(const Coord &c)
{
    if (this->valid(c))
    {
        (*this)[c].setBorder();
        return true;
    }
    else
        return false;
}

bool Board::validForShip(const Ship &p, Coord c)
{
    unsigned char n = p.getSize();
    if (!valid(c + p.getInc() * n)) return false;
    Coord inc = p.getInc();
    for (int i = 0; i < n; i++)
    {
        if (!(*this)[c].valid()) return false;
        c += inc;
    }
    return true;
}
