#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    enum Status
    {
        WAITING, ACTION, WIN
    };
    public:
        Player(Board *bValue, Map *mValue);
        virtual ~Player();
        void setSquadron();
    protected:
        Status state;
        Board *board;
        Map *map;
        const int N;
        const int types;
        Ship *squadron[N];
    private:
};

#endif // PLAYER_H
