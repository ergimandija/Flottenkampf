#include "PlayerController.h"

PlayerController::PlayerController()
{
    //ctor
}

PlayerController::~PlayerController()
{
    //dtor
}


int PlayerController::pickTarget(){
    while(true){
    int target;
    std::cout << "declare your target: " << std::endl;
    std::cin >> target;
    if(target > -1 && target < 9){
        return target;
    }
    std::cout << "Input invalid, Try again!" << std::endl;
    }
    return 0;

}


char PlayerController::pickMovement(){
    while(true){
    char direction;
    std::cout << "pick direction: " << std::endl;
    std::cin >> direction;
    if(direction == 'w' || direction == 'a' || direction == 's' || direction == 'd'){
        return direction;
    }
    std::cout << "Input invalid, Try again!" << std::endl;
    }
    return ' ';

}
