#ifndef TEAM_H
#define TEAM_H
#include <vector>
#include <memory>
#include "IShip.h"
#include <iostream>
#include "EnemyFactory.h"
#include <windows.h>

class Team
{
    public:
        Team();
        Team(int memberCount);
        virtual ~Team();
        void addMember(IShip& s);
        void executeTurn(int index,std::unique_ptr<Team>& targetTeam);
        int getAliveMemberCount();
        void createCharacters(bool isPlayer);
        std::unique_ptr<IShip>& getMember(int index);
        void setId(int id);
        int getId();
        int getMemberCount() const;
        void setIdle();
    protected:

    private:
        int _memberCount;
        std::vector<std::unique_ptr<IShip>> _members;
        int _id;

};

#endif // TEAM_H
