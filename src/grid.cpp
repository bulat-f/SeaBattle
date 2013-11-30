#include "grid.h"

Grid::Grid(Coord& value) : size(value)
{
    m_grid = new int [size.x * size.y];
}

Grid::~Grid()
{
    delete [] m_grid;
}

int Grid::convert(const Coord& p) const
{
    return p.x + p.y * size.x;
}

bool Grid::valid(const Coord& p) const
{
    return p.x >= 0 && p.x < width() &&
            p.y >= 0 && p.y < height();
}

int& Grid::operator[](const Coord& p)
{
    return m_grid[convert(p)];
}

const int& Grid::operator[](const Coord& p) const
{
    return m_grid[convert(p)];
}
