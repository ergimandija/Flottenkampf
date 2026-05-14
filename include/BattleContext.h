#ifndef BATTLECONTEXT_H
#define BATTLECONTEXT_H
#include "Team.h"
#include <memory>

class BattleContext
{
    public:
        BattleContext(std::unique_ptr<Team>& teamA, std::unique_ptr<Team>& teamB);
        virtual ~BattleContext();

    protected:

    private:
        std::unique_ptr<Team>& _teamA;
        std::unique_ptr<Team>& _teamB;
};

#endif // BATTLECONTEXT_H
