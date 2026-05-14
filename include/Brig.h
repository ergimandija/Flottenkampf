#ifndef BRIG_H
#define BRIG_H
#include "Ship.h"

class Brig: public Ship
{
    public:
        Brig();
        virtual ~Brig();
        void attack(std::unique_ptr<IShip>& target) override;

    protected:

    private:
};

#endif // BRIG_H
