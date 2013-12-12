#include "boardelemview.h"

#include <iostream>

using namespace std;

BoardElemView::BoardElemView()
{
    //ctor
}

BoardElemView::~BoardElemView()
{
    //dtor
}

void BoardElemView::show(const BoardElement &elem)
{
    switch (elem.state)
    {
    case BoardElement::ALIVE:
        cout << "# | ";
        return;
    case BoardElement::DEAD:
        cout << "X | ";
        return;
    default:
        cout << "  | ";
    }
}
