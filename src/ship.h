#ifndef SHIP_H
#define SHIP_H

#include "coord.h"

#include <iostream>

using namespace std;

class Ship
{
    public:
        enum position
        {
            HORIZONTAL, VERTICAL
        };
        Ship(unsigned char life_value = 1, position pos_value = HORIZONTAL);
        virtual ~Ship();
        void hit();
        bool isAlive() const;
        unsigned char getSize() const;
        Coord getInc() const;
        void setPos(position pValue) { pos = pValue; }
    protected:
        unsigned char life;
        position pos;
    private:
};

istream &operator>> (istream &in, Ship::position &pos);

#endif // SHIP_H
