#ifndef ELEMENT_H
#define ELEMENT_H

#include "ship.h"
#include "coord.h"

// #include "hit.h"

class Element
{
    public:
        Element();
        virtual ~Element();
        virtual bool valid() = 0;
        virtual bool setBorder() = 0;
        Coord getInc();
        bool haveParent();
    protected:
        Ship* parent;
    private:
};

#endif // ELEMENT_H
