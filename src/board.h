#ifndef BOARD_H
#define BOARD_H

#include "grid.h"
#include "element.h"

class Board : public Grid<Element>
{
    public:
        Board();
        virtual ~Board();
    protected:
    private:
};

#endif // BOARD_H
