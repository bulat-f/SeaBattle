#include <iostream>
#include "game.h"

using namespace std;
int main()
{
    Coord c(8, 8);
    Game game(c);
    game.run();
    return 0;
}
