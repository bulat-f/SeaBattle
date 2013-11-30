#ifndef ELEMENT_
#define ELEMENT_H

#include "ship.h"
#include "hit.h"
#include "coord.h"

class Element
{
    public:
        enum type
        {
            ALIVE, DEAD, MISS, BORDER, WATER
        };
        Element();
        virtual ~Element();
        h hit();
        bool valid();
        void setShip(Ship *s);
    protected:
        Ship* parent;
        type state;
    private:
};

#endif // ELEMENT_H
