#include "AIController.h"

AIController::AIController()
{
    //ctor
}

AIController::~AIController()
{
    //dtor
}

int AIController::pickTarget(){
    return rand()%9;
}


char AIController::pickMovement(){
    int direction = rand()%4;
    switch(direction){
    case 0:
        return 'w';
    case 1:
        return 'a';
    case 2:
        return 's';
    default:
        return 'd';
    }

}
