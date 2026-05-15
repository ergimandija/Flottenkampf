#include "BattleContext.h"



BattleContext::BattleContext(std::unique_ptr<Team>& teamA, std::unique_ptr<Team>& teamB): _teamA(teamA), _teamB(teamB)
{

}

BattleContext::~BattleContext()
{
    //dtor
}


std::unique_ptr<Team>& BattleContext::getEnemiesOf(std::unique_ptr<Team>& team){
        if(team == _teamA){
            return _teamB;
        }
        return _teamA;
}
