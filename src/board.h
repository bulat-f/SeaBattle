#ifndef BOARD_H
#define BOARD_H

#include "grid.h"
#include "elem.h"

class Board : public Grid<Elem>
{
    public:
        Board();
        virtual ~Board();
    protected:
    private:
};

#endif // BOARD_H
