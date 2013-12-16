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

Coord Coord::defaultSize()
{
    return Coord(10, 10);
}

Coord Coord::up()
{
    return Coord(0, 1);
}

Coord Coord::rigth()
{
    return Coord(1, 0);
}

istream &operator>> (istream &in, Coord &c)
{
    char x, y;
    in >> x >> y;
    if (letter(x)) x -= 'a'; else x -= '1';
    y -= '1';
    c.x = x;
    c.y = y;
    return in;
}

ostream &operator<< (ostream &out, Coord &c)
{
    out << c.x << " " << c.y;
    return out;
}
