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

bool Board::setShip(Ship &p, Coord c)
{
    if (!validForShip(p, c)) return false;
    unsigned char n = p.getSize();
    Coord inc = p.getInc();
    for (int i = 0; i < n; i++)
    {
        ((*this)[c]).setShip(&p);
        c += inc;
    }
    return true;
}

bool Board::validForShip(const Ship &p, Coord c)
{
    unsigned char n = p.getSize();
    Coord inc = p.getInc();
    for (int i = 0; i < n; i++)
    {
        if (!(*this)[c].valid()) return false;
        c += inc;
    }
    return true;
}
