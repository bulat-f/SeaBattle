#include "computer.h"

#include <cstdlib>
#include <ctime>

Computer::Computer(Board *bValue, Map *mValue): Player(bValue, mValue), xSize(board->width()), ySize(board->height()),
                                                curHead(Coord::invalid()), curEnd(Coord::invalid())
{
    x = new int [xSize];
    y = new int [ySize];
    init(x, xSize);
    init(y, ySize);
    shuffle(x, xSize);
}

Computer::~Computer()
{
    delete [] x;
    delete [] y;
}

void Computer::assignSquadron()
{
    bool flag;
    unsigned char pos;
    int i = 0, j = 0, prev_i, prev_j;
    Coord c;
    shuffle(y, ySize);
    srand(time(NULL));
    while (!isComplete())
    {
        prev_i = i;
        prev_j = j;
        flag = false;
        pos = rand() % 2;
        while (!flag)
        {
            c.x = x[i];
            c.y = y[j];
            flag = setShip(c, pos);
            if (i < xSize)
            {
                i++;
            }
            else
            {
                if (j < ySize)
                {
                    j++;
                    i = 0;
                }
                else
                {
                    i = prev_i;
                    j = prev_j;
                    pos++;
                    pos %= 2;
                }
            }
        }
    }
}

Hit Computer::hit()
{
    Hit result;
    if (curHead.valid())
    {
        result = map->hit(curHead + next);

        switch (result.HitInfo)
        {
            case Hit::KILL:
                curHead = Coord::invalid();
                curEnd = Coord::invalid();
                break;
            case Hit::HIT:
                curHead += next;
                break;
            default:
                if ((curHead - curEnd).isNil())
                {
                    next.rotate();
                }
                else
                {
                    Coord tmp = curHead;
                    curHead = curEnd;
                    curEnd = tmp;
                    next *= -1;
                    break;
                }
        }
    }
    else
    {
        result = randomHit();
    }
    return result;
}

Hit Computer::randomHit() // можно перенести в hit()
{
    int x, y;
    Coord c;
    Hit result;
    srand(time(NULL));
    do
    {
        x = rand() % xSize;
        y = rand() % ySize;
        c.x = x; c.y = y;
        result = map->hit(c);
    }
    while (!result.valid());
    if (result.HitInfo == Hit::HIT)
    {
        curHead = curEnd = c;
        next = Coord(1, 0);
    }
    return result;
}

void Computer::shuffle(int *a, int n)
{
    int k, tmp;
    for (int i = 0; i < n; i++)
    {
        srand(time(NULL));
        k = rand() % n;
        tmp = a[i];
        a[i] = a[k];
        a[k] = tmp;
    }
}
