#ifndef MAPELEMENT_H
#define MAPELEMENT_H

#include "element.h"
#include "hit.h"
#include "ship.h"

class MapElement: public Element
{
    friend class View;
    friend class MapElemView;
    public:
        enum type
        {
            DEAD, MISS, BORDER, WATER // еще раз подумать
        };
        MapElement();
        virtual ~MapElement();
        virtual bool valid();
        virtual bool setBorder();
        void hit(Hit result);
    protected:
        Ship* parent;
        type state;
    private:
};

#endif // MAPELEMENT_H
