#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        enum Status
        {

        };
        Game();
        virtual ~Game();

        void run();
    protected:
        Status state;
    private:
};

#endif // GAME_H
