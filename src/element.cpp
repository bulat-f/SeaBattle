#include "element.h"

#include <cstddef>

Element::Element(): parent(NULL)
{
    //ctor
}

Element::~Element()
{
    //dtor
}

Coord Element::getInc()
{
    return parent->getInc();
}

bool Element::haveParent()
{
    return parent != NULL;
}
