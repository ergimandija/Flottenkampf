#include "ShipFactory.h"

ShipFactory::ShipFactory()
{
    //ctor
}

ShipFactory::~ShipFactory()
{
    //dtor
}

std::unique_ptr<Ship> ShipFactory::createShip(ShipType stype){
     std::unique_ptr ship;
    switch(stype){
    case GALLEON:
        ship = std::make_unique<Galleon>();
        break;
    case BRIG:
        ship = std::make_unique<Brig>();
        break;
    case SCHOONER:
        ship = std::make_unique<Schooner>();
        break;
    }
    return ship;

}
