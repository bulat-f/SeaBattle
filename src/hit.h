#ifndef HIT_H
#define HIT_H

#include <cstddef>

#include "ship.h"

class Hit
{
    public:
        enum Info
        {
            KILL, HIT, MISS, INVALID
        };
        Hit(Info iValue = INVALID, Ship *sValue = NULL);
        ~Hit();
        Info HitInfo;
        Ship *destroyed;
    protected:
};

#endif // HIT_H
