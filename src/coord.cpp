#include "coord.h"

Coord::Coord(int x, int y): x(x), y(y)
{
}

Coord::~Coord()
{
}

Coord Coord::operator+(const Coord& other) const
{
    return Coord(x + other.x, y + other.y);
}

Coord Coord::operator-(const Coord& other) const
{
    return Coord(x - other.x, y - other.y);
}

Coord Coord::operator*(int n) const
{
    return Coord(x * n, y * n);
}

Coord& Coord::operator+=(const Coord& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Coord& Coord::operator-=(const Coord& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

bool Coord::operator==(const Coord& other) const
{
    return x == other.x && y == other.y;
}
;
bool Coord::operator!=(const Coord& other) const
{
    return !operator==(other);
}

bool Coord::valid() const
{
    return x >= 0 && y >= 0;
}

Coord Coord::invert()
{
    Coord result(y, x);
    return result;
}

Coord Coord::invalid()
{
    return Coord(-1, -1);
}
