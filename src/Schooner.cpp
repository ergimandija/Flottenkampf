#include "Schooner.h"

Schooner::Schooner()
{
    std::cout << "created schooner" << std::endl;
    _hull = 250;
    _size = 8;
    _damage = 50;
}

Schooner::~Schooner()
{
    //dtor
}

void Schooner::attack(std::unique_ptr<IShip>& target){
    std::cout << "Ship" << _id << "trifft kritisch " << target->getId() << std::endl;
    target->recieveDamage(_damage);
}
