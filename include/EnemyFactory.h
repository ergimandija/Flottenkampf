#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H
#include "AIController.h"
#include "ShipFactory.h"
#include "EnemyBrig.h"
#include "EnemyGalleon.h"
#include "EnemySchooner.h"

class EnemyFactory: public ShipFactory
{
    public:
        EnemyFactory();
        virtual ~EnemyFactory();
        std::unique_ptr<Ship> createShip(ShipType stype) override;
    protected:

    private:
};

#endif // ENEMYFACTORY_H
