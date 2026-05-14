#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "World.h"
#include "Team.h"
#include <vector>
#include <memory>
class Game
{
    public:
        Game();
        virtual ~Game();
        void start();

    protected:

    private:
        World _world;
        std::vector<std::unique_ptr<Team>> _teams;


};

#endif // GAME_H
