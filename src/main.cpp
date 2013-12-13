#include <iostream>
#include "game.h"

using namespace std;
int main()
{
    Coord c(5, 5);
    Game game(c);
    game.run();
    return 0;
}
