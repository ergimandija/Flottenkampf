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
    BattleContext ctx(_teams[0],_teams[1]);
    for(auto& team : _teams){
        team->createCharacters();
    }

    do {
    for(auto& team: _teams){
        if(team->getAliveMemberCount() == 0){
            _isFinished = true;
            std::cout << "Team " << team->getId() << " lost :(" << std::endl;
            std::cout << "Team " << ctx.getEnemiesOf(team)->getId() << " won!" << std::endl;
            break;
        }
        team->executeTurn(ctx.getEnemiesOf(team));

    }
    } while(!_isFinished);

}



