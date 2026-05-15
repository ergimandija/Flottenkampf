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
        void executeTurn(std::unique_ptr<Team>& targetTeam);
        int getAliveMemberCount();
        void createCharacters();
        std::unique_ptr<IShip>& getMember(int index);
        void setId(int id);
        int getId();
    protected:

    private:
        int _memberCount;
        std::vector<std::unique_ptr<IShip>> _members;
        int _id;

};

#endif // TEAM_H
