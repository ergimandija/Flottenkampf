#ifndef GALLEON_H
#define GALLEON_H
#include "Ship.h"

class Galleon: public Ship
{
    public:
        Galleon();
        virtual ~Galleon();
        void attack(std::unique_ptr<IShip>& target) override;

    protected:

    private:
};

#endif // GALLEON_H
