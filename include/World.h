#ifndef WORLD_H
#define WORLD_H
#include "Team.h"
#include <SFML/Graphics.hpp>

class World
{
    public:
        World(int xSize, int ySize);
        World();
        virtual ~World();
        void render(std::vector<std::unique_ptr<Team>>& teams, sf::RenderWindow& window);
        void renderField(sf::RenderWindow& window, float tileSize);
        void spawnTeam(std::unique_ptr<Team>& t, bool isEnemy);

    protected:

    private:
        int _xSize;
        int _ySize;

};

#endif // WORLD_H
