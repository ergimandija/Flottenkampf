#ifndef SHIPFACTORY_H
#define SHIPFACTORY_H
#include "Ship.h"
#include <string>
#include <memory>

enum ShipType {
    BRIG,
    GALLEON,
    SCHOONER
};


enum Behaviour {
    PLAYER,
    ENEMY
};

class ShipFactory
{
    public:
        ShipFactory();
        virtual ~ShipFactory();
        static std::unique_ptr<Ship> createShip(ShipType stype,Behaviour btype);
    protected:

    private:
};

#endif // SHIPFACTORY_H
