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
    int i = 0, j = 0;
    Coord c;
    shuffle(y, ySize);
    Show(x, xSize);
    Show(y, ySize);
    while (!isComplete())
    {
        flag = false;
        while (!flag)
        {
            c.x = x[i];
            c.y = y[j];
            flag = setShip(c);
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
                    return;
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

void Computer::Show(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
