#include "Game.h"

Game::Game()
{

    for(int i=0;i<2;i++){
        std::unique_ptr<Team> t = std::make_unique<Team>(9);
        _teams.push_back(std::move(t));
        _teams[i]->setId(i+1);
    }
    _world = World(20,20);
    _isFinished = false;
}

Game::~Game()
{
    //dtor
}

void Game::start(){
     sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Flottenkampf");

    BattleContext ctx(_teams[0],_teams[1]);
    bool firstTeam = true;
    for(auto& team : _teams){
        team->createCharacters(firstTeam);
        firstTeam = false;
    }
    _world.spawnTeam(_teams[0],false);
    _world.spawnTeam(_teams[1],true);
    _world.render(_teams, window);

    do {
    for(int i=0;i<_teams[0]->getMemberCount();i++){
        for(auto& team: _teams){

            if(team->getAliveMemberCount() == 0){
                _isFinished = true;
                std::cout << "Team " << team->getId() << " lost :(" << std::endl;
                std::cout << "Team " << ctx.getEnemiesOf(team)->getId() << " won!" << std::endl;
                return;
                }
            team->executeTurn(i,ctx.getEnemiesOf(team));
            _world.render(_teams, window);
            }
    }
    } while(!_isFinished);

}



