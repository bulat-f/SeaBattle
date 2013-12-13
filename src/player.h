#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "map.h"
#include "ship.h"

class Player
{
    enum Status
    {
        WAITING, ACTION, WIN
    };
    public:
        Player(Board *bValue, Map *mValue);
        virtual ~Player();
        bool setShip(const Coord &c, Ship::position pos = Ship::HORIZONTAL);
        bool isComplete() { return counter == N; }
    protected:
        Status state;
        Board *board;
        Map *map;
        const int N = 4;
        const int types = 1;
        Ship *squadron[4];
        int counter;
    private:
};

#endif // PLAYER_H
