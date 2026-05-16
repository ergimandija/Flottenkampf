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
    int rolledAmount;
    do {
    rolledAmount = Dice::roll(10);
    std::cout << "rolled a " << rolledAmount << std::endl;
    std::cout << "Ship " << _id << " bombardiert Ship " << target->getId() << std::endl;
    } while(target->recieveDamage(_damage,rolledAmount));
}
