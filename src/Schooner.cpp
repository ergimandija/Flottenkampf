#include "Schooner.h"

Schooner::Schooner()
{
    std::cout << "created schooner" << std::endl;
    _hull = 75;
    _size = 4;
    _damage = 30;
}

Schooner::~Schooner()
{
    //dtor
}

void Schooner::attack(std::unique_ptr<IShip>& target){
    int rolledAmount = Dice::roll(10);
    std::cout << "rolled a " << rolledAmount << std::endl;
    if(rolledAmount > 8){
        std::cout << "Ship " << _id << " trifft kritisch Ship " << target->getId() << std::endl;
        target->recieveDamage(_damage*2,rolledAmount);
    } else {
        std::cout << "Ship " << _id << " greift Ship " << target->getId() << " an" << std::endl;
        target->recieveDamage(_damage, rolledAmount);
    }
}
