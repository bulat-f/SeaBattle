#ifndef GAME_H
#define GAME_H

#include "coord.h"
#include "player.h"
#include "computer.h"
#include "board.h"
#include "map.h"
#include "view.h"

class Game
{
    public:
        enum Status
        {

        };
        Game(const Coord &c = Coord(10, 10));
        virtual ~Game();

        void run();
    protected:
        Status state;
        Board board1, board2;
        Map map1, map2;
        Player player;
        Computer computer;
        View view1, view2;
    private:
};

#endif // GAME_H
