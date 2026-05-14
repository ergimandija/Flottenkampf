#ifndef WORLD_H
#define WORLD_H
#include "Team.h"

class World
{
    public:
        World(int xSize, int ySize);
        World();
        virtual ~World();
        void render();
        void spawnTeam(Team& t);
    protected:

    private:
        int _xSize;
        int _ySize;

};

#endif // WORLD_H
