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

bool Board::setShip(Ship &p, Coord c) // TODO: Исправить проблему выхода за границы
{
    if (!validForShip(p, c)) return false;
    unsigned char n = p.getSize();
    Coord border, inc = p.getInc();
    border = inc.invert();
    (*this)[c - inc].setBorder();
    (*this)[c - inc + border].setBorder();
    (*this)[c - inc - border].setBorder();
    for (int i = 0; i < n; i++)
    {
        (*this)[c].setShip(&p);
        (*this)[c + border].setBorder();
        (*this)[c - border].setBorder();
        c += inc;
    }
    (*this)[c].setBorder();
    (*this)[c + border].setBorder();
    (*this)[c - border].setBorder();
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
