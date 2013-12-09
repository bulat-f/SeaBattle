#ifndef ELEMENT_H
#define ELEMENT_H

#include "hitinfo.h"

class Element
{
    public:
        Element();
        virtual ~Element();
        virtual HitInfo hit() = 0;
        virtual bool valid() = 0;
    protected:
    private:
};

#endif // ELEMENT_H
