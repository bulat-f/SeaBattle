#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "map.h"
#include "ship.h"
#include "hit.h"

class Player
{
    enum Status
    {
        WAITING, ACTION, WIN
    };
    public:
        Player(Board *bValue, Map *mValue);
        virtual ~Player();
        bool setShip(const Coord &c, unsigned char pos = 0);
        Hit hit(const Coord &c);
        bool isComplete() { return counter == N; }
        bool isLoser();
    protected:
        Status state;
        Board *board;
        Map *map;
        const int N = 4;
        const int types = 1;
        Ship **squadron;
        int counter;
    private:
};

#endif // PLAYER_H
