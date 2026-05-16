#include "Ship.h"

Ship::Ship()
{
    _isAlive = true;
    _state = IDLE;

}

Ship::Ship(int x,int y)
{
    _isAlive = true;
    _state = IDLE;
    _posX = x;
    _posY = y;

}

Ship::~Ship()
{
    //dtor
}

int Ship::getId() const {
    return _id;
}

void Ship::setId(int id){
    _id = id;
}
void Ship::move(){
    std::cout << "moving" << std::endl;
}

void Ship::moveUp(){

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

bool Ship::recieveDamage(int amount, int rolledAmount){

    if(this->isAlive()){

        if(rolledAmount >= _size){
            _hull -= amount;
            if(_hull <= 0){
                std::cout << "Ship " << _id << " defeated" << std::endl;
                _isAlive = false;
            }
            return true;
        }

        std::cout << "attack failed" << std::endl;
        return false;

    }
    std::cout << "Ship already defeated" << std::endl;
    return false;
}

bool Ship::isAlive(){
    return _isAlive;
}

 void Ship::setController(std::unique_ptr<IController>& controller){
            _controller = std::move(controller);
 }

std::unique_ptr<IController>& Ship::getController()  {
            return _controller;
}

std::string Ship::getTexturePath() const {
        return _texturePath;
}
