#include "mapelemview.h"

#include <iostream>

using namespace std;

MapElemView::MapElemView()
{
    //ctor
}

MapElemView::~MapElemView()
{
    //dtor
}

void MapElemView::show(const MapElement &elem)
{
    switch (elem.state)
    {
    case MapElement::MISS:
        cout << "' | ";
        return;
    case MapElement::DEAD:
        cout << "X | ";
        return;
    case MapElement::type::BORDER:
        cout << "b | ";
        return;
    default:
        cout << "  | ";
    }
}
