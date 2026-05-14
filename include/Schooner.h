#ifndef SCHOONER_H
#define SCHOONER_H
#include "Ship.h"

class Schooner: public Ship
{
    public:
        Schooner();
        virtual ~Schooner();
        void attack(std::unique_ptr<IShip>& target) override;
    protected:

    private:
};

#endif // SCHOONER_H
