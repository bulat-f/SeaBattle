#ifndef MAPELEMVIEW_H
#define MAPELEMVIEW_H

#include "elemview.h"
#include "mapelement.h"


class MapElemView//: ElemView
{
    public:
        MapElemView();
        virtual ~MapElemView();
        static void show(const MapElement &elem);
    protected:
    private:
};

#endif // MAPELEMVIEW_H
