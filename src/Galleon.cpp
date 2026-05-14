#include "Galleon.h"

Galleon::Galleon()
{
    std::cout << "created galleon" << std::endl;
    _hull = 250;
    _size = 8;
    _damage = 50;
}

Galleon::~Galleon()
{
    //dtor
}

void Galleon::attack(std::unique_ptr<IShip>& target){
    std::cout << "Ship" << _id << "bombardiert " << target->getId() << std::endl;
    target->recieveDamage(_damage);
}
