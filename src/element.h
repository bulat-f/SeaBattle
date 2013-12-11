#ifndef ELEMENT_H
#define ELEMENT_H

// #include "hit.h"

class Element
{
    public:
        Element();
        virtual ~Element();
        // virtual Hit hit() = 0;
        virtual bool valid() = 0;
    protected:
    private:
};

#endif // ELEMENT_H
