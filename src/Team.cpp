#include "Team.h"

Team::Team()
{
    std::cout << "Team created" << std::endl;
}

Team::~Team()
{
    //dtor
}

int Team::getAliveMemberCount(){
    int counter = 0;
    for(auto& member: _members){
        if(member->isAlive()){
            counter++;
        }

    }
    return counter;
}

Team::Team(int memberCount){
    _memberCount = memberCount;
}


void Team::createCharacters(){
    std::cout << "creating character for team " << std::endl;
    for(int i=0; i< _memberCount;i++){
        _members.push_back(ShipFactory::createShip(static_cast<ShipType>(rand()%3)));
        _members[i]->setId(i);
    }
}

void Team::setId(int id){
        _id = id;
}

std::unique_ptr<IShip>& Team::getMember(int index){
            return _members[index];
}

void Team::executeTurn(std::unique_ptr<Team>& targetTeam){
    std::cout << "Team " << _id << "'s turn---------------------------------------" << std::endl;
    for(auto& member: _members){
            if(member->isAlive()){
                    member->attack(targetTeam->getMember(rand()%9));
                    if(targetTeam->getAliveMemberCount() == 0){
                        break;
                    }
            }
    }
}


int Team::getId(){
    return _id;
}
