#include "Ship.h"

Ship::Ship()
{
    _isAlive = true;
    _state = IDLE;

}

Ship::~Ship()
{
    //dtor
}

int Ship::getId() const {
    return _id;
}


void Ship::move(){
    std::cout << "moving" << std::endl;
}

int Ship::getXPosition() const {
    return _posX;
}

int Ship::getYPosition() const {
    return _posY;
}

void Ship::setXPosition(int xPos){
    _posX = xPos;
}

void Ship::setYPosition(int yPos){
    _posY = yPos;
}

void Ship::recieveDamage(int amount){
    _hull -= amount;
    if(_hull <= 0){
        std::cout << "Ship" << _id << "defeated" << std::endl;
        _isAlive = false;
    }
}
