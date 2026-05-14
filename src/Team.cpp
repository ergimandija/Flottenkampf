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
    return 1;
}

Team::Team(int memberCount){
    _memberCount = memberCount;
}

//void Team::addMember(IShip& s){
//
//}

void Team::createCharacters(){
    std::cout << "creating character for team " << std::endl;
    for(int i=0; i< _memberCount;i++){
        _members.push_back();
    }

}
