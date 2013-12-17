#ifndef COORD_H
#define COORD_H

#include <iostream>

using namespace std;

class Coord
{
    public:
        Coord() {}
        Coord(int x, int y);
        virtual ~Coord();

        int x;
        int y;

        Coord operator+(const Coord& other) const;
        Coord operator-(const Coord& other) const;
        Coord operator*(int n) const;
        Coord& operator+=(const Coord& other);
        Coord& operator-=(const Coord& other);

        bool operator==(const Coord& other) const;
        bool operator!=(const Coord& other) const;
        bool valid() const;

        Coord invert();

        static Coord invalid();
        static Coord defaultSize();
        static Coord up();
        static Coord rigth();
    protected:
    private:
};

inline bool letter(const char &ch)
{
    return (ch >= 'a' && ch <= 'z');
}

istream& operator>>(istream &in, Coord &c);
ostream& operator<<(ostream &out, const Coord &c);

#endif // COORD_H
