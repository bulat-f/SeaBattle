#ifndef BOARDELEMVIEW_H
#define BOARDELEMVIEW_H

#include "elemview.h"
#include "boardelement.h"


class BoardElemView//: ElemView
{
    public:
        BoardElemView();
        virtual ~BoardElemView();
        static void show(const BoardElement &elem);
    protected:
    private:
};

#endif // BOARDELEMVIEW_H
