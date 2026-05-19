#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "World.h"
#include "Team.h"
#include <vector>
#include <memory>
#include "BattleContext.h"
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
        bool _isFinished;




};

#endif // GAME_H
