#ifndef SHIP_H
#define SHIP_H

#include "coord.h"


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
    protected:
        unsigned char life;
        position pos;
    private:
};

#endif // SHIP_H
