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


void Team::createCharacters(bool isPlayer){
    std::cout << "creating character for team " << std::endl;
    std::unique_ptr<ShipFactory> factory = std::make_unique<ShipFactory>();
    if(!isPlayer){
        factory = std::move(std::make_unique<EnemyFactory>());
    }
    for(int i=0; i< _memberCount;i++){
        _members.push_back(factory->createShip(static_cast<ShipType>(rand()%3)));
        _members[i]->setId(i);
    }
}

void Team::setId(int id){
        _id = id;
}

std::unique_ptr<IShip>& Team::getMember(int index){
            return _members[index];
}

void Team::executeTurn(int index,std::unique_ptr<Team>& targetTeam){
    auto& member = _members[index];
    if(member->isAlive()){
    std::cout << "Team " << _id <<"'s turn-----------------------" << std::endl;


                    if(targetTeam->getAliveMemberCount() == 0){
                        return;
                    }
                    member->attack(targetTeam->getMember(member->getController()->pickTarget()));

            }

}


int Team::getId(){
    return _id;
}

int Team::getMemberCount() const {
    return _memberCount;
}
