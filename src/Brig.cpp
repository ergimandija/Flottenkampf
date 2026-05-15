#include "Brig.h"

Brig::Brig()
{
    std::cout << "created Brig" << std::endl;
    _hull = 150;
    _size = 6;
    _damage = 60;
}

Brig::~Brig()
{
    //dtor
}

void Brig::attack(std::unique_ptr<IShip>& target){
    std::cout << "Ship " << _id << " greift Zielsuchend Ship " << target->getId() << " an" << std::endl;
    target->recieveDamage(_damage);

}
