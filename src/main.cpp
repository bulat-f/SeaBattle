#include <iostream>
#include "board.h"
#include "coord.h"
#include "ship.h"
#include "map.h"

using namespace std;
int main()
{
    Coord c(8, 8);
    Board b(c);
    Map m(&b);
    Ship p(4);
    c.x = 0; c.y = 0;
    b.setShip(&p, c);
    cout << b.getSize().x << " x " << b.getSize().y << endl;
    int n = b.getSize().x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c.x = j;
            c.y = i;
            cout << (b[c].valid()?".":"*");
        }

        for (int j = 0; j < n; j++)
        {
            c.x = j;
            c.y = i;
            cout << (m[c].valid()?"+":"*");
        }
        cout << endl;
    }
    return 0;
}
