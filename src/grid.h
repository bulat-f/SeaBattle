#ifndef GRID_H
#define GRID_H

#include "coord.h"

template <typename T>
class Grid
{
    public:
        Grid();
        Grid(const Coord& value);
        virtual ~Grid();

        T& operator[](const Coord& p);
        const T& operator[](const Coord& p) const;

        bool valid(const Coord& p) const;
        inline int width() const { return size.x; }
        inline int height() const { return size.y; }
    protected:
        Coord size;
        T* m_grid;
        void bordered(const Coord &c);
        bool setBorder(const Coord &c);
        int convert(const Coord& p) const;
    private:
};

template <typename T>
Grid<T>::Grid(): size(10, 10)
{
    m_grid = new T[size.x * size.y];
}

template <typename T>
Grid<T>::Grid(const Coord& value): size(value)
{
    m_grid = new T[size.x * size.y];
}

template <typename T>
Grid<T>::~Grid()
{
    delete[] m_grid;
}

template <typename T>
int Grid<T>::convert(const Coord& p) const
{
    return p.x + p.y * size.x;
}

template <typename T>
bool Grid<T>::valid(const Coord& p) const
{
    return p.valid() && (size - p - Coord(1, 1)).valid();//p.x >= 0 && p.x < width() && p.y >= 0 && p.y < height();
}

template <typename T>
T& Grid<T>::operator[](const Coord& p)
{
    return m_grid[convert(p)];
}

template <typename T>
const T& Grid<T>::operator[](const Coord& p) const
{
    return m_grid[convert(p)];
}

template <typename T>
void Grid<T>::bordered(const Coord& c)
{
    if (! m_grid[convert(c)].haveParent()) return;
    Coord border, p = c, inc = m_grid[convert(c)].getInc();
    border = inc.invert();
    while (valid(p) && m_grid[convert(p)].haveParent())
    {
        setBorder(p + border);
        setBorder(p - border);
        p += inc;
    }
    setBorder(p);
    setBorder(p + border);
    setBorder(p - border);

    p = c;
    while (valid(p) && m_grid[convert(p)].haveParent())
    {
        setBorder(p + border);
        setBorder(p - border);
        p -= inc;
    }
    setBorder(p);
    setBorder(p + border);
    setBorder(p - border);
}

template <typename T>
bool Grid<T>::setBorder(const Coord &c)
{
    if (this->valid(c))
    {
        (*this)[c].setBorder();
        return true;
    }
    else
        return false;
}

#endif // GRID_H
