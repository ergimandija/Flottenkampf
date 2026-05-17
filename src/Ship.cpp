#include "Ship.h"

Ship::Ship()
{
    _isAlive = true;
    _state = IDLE;
    _xBorder = 20;
    _yBorder = 20;

}

Ship::Ship(int x,int y)
{
    _isAlive = true;
    _state = IDLE;
    _x = x;
    _y = y;
    _xBorder = 20;
    _yBorder = 20;

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
    switch(_controller->pickMovement()){
    case 'w':
        this->moveUp();
        break;
    case 'a':
        this->moveLeft();
        break;
    case 's':
        this->moveDown();
        break;
    case 'd':
        this->moveRight();
        break;
    default:
        break;

    }

}

void Ship::moveRight(){
    if(_x<_xBorder-2){
    _x+=1;

    }
}
void Ship::moveLeft(){
    if(_x>0){
    _x-=1;
    }
}
void Ship::moveUp(){
    if(_y>0){
    _y-=1;
    }
}
void Ship::moveDown(){
    if(_y<_yBorder-2){
    _y+=1;
    }
}



int Ship::getXPosition() const {
    return _x;
}

int Ship::getYPosition() const {
    return _y;
}

void Ship::setXPosition(int xPos){
    _x = xPos;
}

void Ship::setYPosition(int yPos){
    _y = yPos;
}

bool Ship::recieveDamage(int amount, int rolledAmount){

    if(this->isAlive()){

        if(rolledAmount >= _size){
            _hull -= amount;
            _state = SHOT;
            if(_hull <= 0){
                std::cout << "Ship " << _id << " defeated" << std::endl;
                _isAlive = false;
                _state = DESTROYED;
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

std::string Ship::getTexturePath() {
        return _texturePath+"/"+ this->resolveFileName();
}

std::string Ship::resolveFileName(){
        switch(_state){
        case SHOT:
            return "shot.png";
        case SHOOTING:
            return "shooting.png";
        case DESTROYED:
            return "destroyed.png";
        default:
            return "idle.png";
        }
}


State Ship::getState() const {
    return _state;

}

void Ship::setState(State state) {
    _state = state;
}
