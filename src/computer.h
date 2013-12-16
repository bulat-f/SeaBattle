#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"
#include "hit.h"


class Computer: public Player
{
    public:
        Computer(Board *bValue, Map *mValue);
        virtual ~Computer();
        void assignSquadron();
        Hit hit();
    protected:
    private:
        int *x;
        int *y;
        int xSize, ySize;
        void shuffle(int *a, int n);
        inline void init(int *a, int n)
        {
            for (int i = 0; i < n; i++)
                a[i] = i;
        }
};

#endif // COMPUTER_H
