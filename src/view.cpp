#include "view.h"

#include "boardelemview.h"
#include "mapelemview.h"

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
    cout << endl;
    drawDoubleLine(n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        //cout << endl;
        drawNum(i + 1, 2);
        for (int j = 0; j < n; j++)
        {
            c.x = j;
            c.y = i;
            BoardElemView::show((*board)[c]);
        }
        drawNum(i + 1, 2);
        for (int j = 0; j < n; j++)
        {
            c.x = j;
            c.y = i;
            MapElemView::show((*map)[c]);
        }
        cout << endl;
        drawDoubleLine(n);
        cout << endl;
    }
}

void View::drawLine(int n)
{
    cout << "---";
    for (int j = 0; j < n; j++)
        cout << "+---";
    cout << "- ";
}

void View::drawDoubleLine(int n)
{
    drawLine(n);
    drawLine(n);
}

void View::drawNum(int value, int width)
{
    cout << "|";
    cout.width(width);
    cout << value;
    cout << "| ";
}
