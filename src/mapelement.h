#ifndef MAPELEMENT_H
#define MAPELEMENT_H

#include "element.h"
#include "hit.h"
#include "ship.h"

class MapElement: public Element
{
    public:
        enum type
        {
            DEAD, MISS, WATER // еще раз подумать
        };
        MapElement();
        virtual ~MapElement();
        virtual bool valid();

        void hit(Hit result);
    protected:
        Ship* parent;
        type state;
    private:
};

#endif // MAPELEMENT_H
