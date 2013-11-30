#include "element.h"
#include "coord.h"
#include "hitInfo.h"

Element::Element()
{
    //ctor
}

Element::~Element()
{
    //dtor
}

hitInfo Element::hit()
{
    switch (state)
    {
    case ALIVE:
        state = DEAD;
        parent->hit();
        if (parent->isAlive())
            return hitInfo::DEAD
    }
}
