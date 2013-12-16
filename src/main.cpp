#include <iostream>
#include "game.h"

using namespace std;
int main()
{
    Coord c(6, 6);
    Game game(c);
    game.run();
    return 0;
}
