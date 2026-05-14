#ifndef TEAM_H
#define TEAM_H
#include <vector>
#include <memory>
#include "IShip.h"
#include <iostream>
#include "ShipFactory.h"

class Team
{
    public:
        Team();
        Team(int memberCount);
        virtual ~Team();
        void addMember(IShip& s);
        void executeTurn();
        int getAliveMemberCount();
        void createCharacters();

    protected:

    private:
        int _memberCount;
        std::vector<std::unique_ptr<IShip>> _members;

};

#endif // TEAM_H
