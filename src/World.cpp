#include "World.h"

World::World()
{
    //ctor
}

World::~World()
{
    //dtor
}


World::World(int xSize, int ySize)
{
    _xSize = xSize;
    _ySize = ySize;

}

void World::renderField(sf::RenderWindow& window, float tileSize)
{

        sf::RectangleShape waterTile({tileSize, tileSize});
        sf::Texture texture("water.png");
        waterTile.setTexture(&texture);
        waterTile.setFillColor(sf::Color::Cyan);
          for (int x = 0; x < _xSize; x++)
            {
                for (int y = 0; y < _ySize; y++)
                {
                    waterTile.setPosition({x*tileSize,y*tileSize});
                    window.draw(waterTile);
                }
            }

}

void World::spawnTeam(std::unique_ptr<Team>& t, bool isEnemy)
{
    int startColumn = _xSize-2;
    if(!isEnemy)
    {
        startColumn = 0;
    }
    for(int i=0; i< t->getMemberCount(); i++)
    {
        auto& member = t->getMember(i);
        int x =  startColumn;
        int y =  2*i;
        member->setXPosition(x);
        member->setYPosition(y);
    }

}



void World::render(std::vector<std::unique_ptr<Team>>& teams, sf::RenderWindow& window)
{


    float tileSize = 50.f;
    window.clear();
    renderField(window,tileSize);
    for(int x=0; x < _xSize; x++)
    {
        for(int y=0; y < _ySize; y++)
        {
            for(auto& t: teams)
            {

                for(int i=0; i< t->getMemberCount(); i++)
                {
                    auto& member = t->getMember(i);

                    if(member->getXPosition()==x && member->getYPosition()==y)
                    {


                        sf::Texture texture(member->getTexturePath());
                        sf::RectangleShape ship({tileSize,tileSize});
                        ship.scale({2.f,2.f});
                        ship.setTexture(&texture);
                        ship.setPosition({x*tileSize,y*tileSize});
                        window.draw(ship);

                    }

                }
            }




        }

    }
    window.display();

}
