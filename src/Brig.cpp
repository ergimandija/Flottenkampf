#include "Brig.h"

Brig::Brig()
{
    std::cout << "created Brig" << std::endl;
    _hull = 150;
    _size = 6;
    _damage = 60;
    _texturePath = "sprites/Brig/Player";

}

Brig::~Brig()
{
    //dtor
}

void Brig::attack(std::unique_ptr<IShip>& target){
    _state = SHOOTING;
    int rolledAmount = Dice::roll(10);
    std::cout << "rolled a " << rolledAmount << std::endl;
    std::cout << "Ship " << _id << " greift Zielsuchend Ship " << target->getId() << " an" << std::endl;
    target->recieveDamage(_damage,rolledAmount + 2);


}
