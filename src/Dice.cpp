#include "Dice.h"

Dice::Dice()
{
    //ctor
}

Dice::~Dice()
{
    //dtor
}

int Dice::roll(int sides){
    return (std::rand()%sides)+1;
}
