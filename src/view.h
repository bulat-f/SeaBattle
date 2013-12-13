#ifndef VIEW_H
#define VIEW_H

#include "coord.h"
#include "board.h"
#include "map.h"

class View
{
    public:
        View(Board *bValue, Map *mValue);
        virtual ~View();
        void show();
    protected:
        Board *board;
        Map *map;

        void drawLine(int n);
        void drawDoubleLine(int n);
        void drawNum(int value, int width);
    private:
};

#endif // VIEW_H
