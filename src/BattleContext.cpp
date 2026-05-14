#include "BattleContext.h"

BattleContext::BattleContext(std::unique_ptr<Team>& teamA, std::unique_ptr<Team>& teamB): _teamA(teamA), _teamB(teamB)
{

}

BattleContext::~BattleContext()
{
    //dtor
}
