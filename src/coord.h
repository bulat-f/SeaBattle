#ifndef COORD_H
#define COORD_H


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

        static Coord invalid();
    protected:
    private:
};

#endif // COORD_H
