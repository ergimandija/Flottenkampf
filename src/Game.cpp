#include "Game.h"

Game::Game()
{

    for(int i=0;i<2;i++){
        std::unique_ptr<Team> t = std::make_unique<Team>(9);
        _teams.push_back(std::move(t));
    }

    _world = World(20,20);
}

Game::~Game()
{
    //dtor
}

void Game::start(){
    for(auto& team : _teams){
        team->createCharacters();
    }


}



