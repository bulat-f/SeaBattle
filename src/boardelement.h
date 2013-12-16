#ifndef BOARDELEMENT_H
#define BOARDELEMENT_H

#include "element.h"
#include "hit.h"
#include "ship.h"


class BoardElement: public Element
{
    friend class View;
    friend class BoardElemView;

    public:
        enum type
        {
            ALIVE, DEAD, MISS, BORDER, WATER
        };
        BoardElement();
        virtual ~BoardElement();
        virtual Hit hit();
        virtual bool valid();
        virtual bool setBorder();
        bool setShip(Ship *s);
    protected:
        Ship* parent;
        type state;
    private:
};

#endif // BOARDELEMENT_H
