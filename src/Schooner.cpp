#include "Schooner.h"

Schooner::Schooner()
{
    //ctor
}

Schooner::~Schooner()
{
    //dtor
}

void Schooner::attack(std::unique_ptr<IShip>& target){
    std::cout << "Ship" << _id << "trifft kritisch " << target->getId() << std::endl;
    target->recieveDamage(_damage);
}
