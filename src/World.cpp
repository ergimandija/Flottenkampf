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

void World::renderField(sf::RenderWindow& window)
{
        int tileSize=50;
        sf::RectangleShape waterTile({(float)tileSize, (float)tileSize});
        sf::Texture texture("water.png");
        waterTile.setTexture(&texture);
          for (int x = 0; x < _xSize; x++)
            {
                for (int y = 0; y < _ySize; y++)
                {
                    waterTile.setPosition({static_cast<float>(x*tileSize),static_cast<float>(y*tileSize)});
                    window.draw(waterTile);
                }
            }

}

void World::spawnTeam(std::unique_ptr<Team>& t, bool isEnemy)
{
    int startColumn = _xSize-1;
    if(!isEnemy)
    {
        startColumn = 0;
    }
    for(int i=0; i< t->getMemberCount(); i++)
    {
        auto& member = t->getMember(i);
        int x =  2*i;
        int y =  startColumn;
        member->setXPosition(x);
        member->setYPosition(y);
    }

}




void World::render(std::vector<std::unique_ptr<Team>>& teams, sf::RenderWindow& window)
{


    for(int x=0; x < _xSize; x++)
    {
        for(int y=0; y < _ySize; y++)
        {
            bool shipHere = false;
            for(auto& t: teams)
            {

                for(int i=0; i< t->getMemberCount(); i++)
                {
                    auto& member = t->getMember(i);
                    if(member->getXPosition()==x && member->getYPosition()==y)
                    {
                        shipHere = true;
                    }
                }
            }
            else
            {
                std::cout << "X  " ;
            }
             renderField(window);
             window.display();
        }
        std::cout << std::endl;

    }

}
