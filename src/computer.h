#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"


class Computer: public Player
{
    public:
        Computer(Board *bValue, Map *mValue);
        virtual ~Computer();
        void assignSquadron();
    protected:
    private:
};

#endif // COMPUTER_H
