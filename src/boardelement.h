#ifndef BOARDELEMENT_H
#define BOARDELEMENT_H

#include "element.h"
#include "hitinfo.h"
#include "ship.h"


class BoardElement: public Element
{
    public:
        enum type
        {
            ALIVE, DEAD, MISS, BORDER, WATER
        };
        BoardElement();
        virtual ~BoardElement();
        virtual HitInfo hit();
        virtual bool valid();
        bool setShip(Ship *s);
    protected:
        Ship* parent;
        type state;

        friend class Viewer;
    private:
};

#endif // BOARDELEMENT_H
