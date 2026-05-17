#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{
    //ctor
}

EnemyFactory::~EnemyFactory()
{
    //dtor
}

std::unique_ptr<Ship> EnemyFactory::createShip(ShipType stype){
     std::unique_ptr<Ship> ship;
    switch(stype){
    case GALLEON:
        ship = std::make_unique<EnemyGalleon>();

        break;
    case BRIG:
        ship = std::make_unique<EnemyBrig>();
        break;
    case SCHOONER:
        ship = std::make_unique<EnemySchooner>();
        break;
    }
    std::unique_ptr<IController> controller = std::make_unique<AIController>();
    ship->setController(controller);
    return ship;

}
