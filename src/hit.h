#ifndef HIT_H
#define HIT_H

#include <cstddef>
#include <iostream>

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

ostream &operator<< (ostream &out, const Hit info);
#endif // HIT_H
