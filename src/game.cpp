#include "game.h"

#include "player.h"
#include "board.h"
#include "map.h"

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
    Board board1, board2;
    Map map1(&board2), map2(&board1);
    Player player1(&board1, &map1), player2(&board2, &map2);
    player1.setSquadron();
    player2.setSquadron();
}
