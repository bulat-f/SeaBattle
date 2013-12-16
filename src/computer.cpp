#include "computer.h"

#include <cstdlib>
#include <ctime>

Computer::Computer(Board *bValue, Map *mValue): Player(bValue, mValue), xSize(board->width()), ySize(board->height())
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
    Show(x, xSize); // DEBUG
    Show(y, ySize); // DEBUG
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

void Computer::Show(int *a, int n) // DEBUG
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
