#include "view.h"

#include "boardelemview.h"
#include <iostream>

using namespace std;

View::View(Board *bValue, Map *mValue): board(bValue), map(mValue)
{
    //ctor
}

View::~View()
{
    //dtor
}

void View::show()
{
    Coord c;
    int n = board->width();
    for (int i = 0; i < n; i++)
    {
        cout << "| ";
        for (int j = 0; j < n; j++)
        {
            c.x = j;
            c.y = i;
            BoardElemView::show((*board)[c]);
        }
        cout << endl;
        for (int j = 0; j < n; j++)
            cout << "----";
        cout << endl;
    }
}
