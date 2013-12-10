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
    return p.valid() && (size - p).valid();//p.x >= 0 && p.x < width() && p.y >= 0 && p.y < height();
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

#endif // GRID_H
