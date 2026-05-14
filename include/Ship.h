#ifndef SHIP_H
#define SHIP_H
#include "IShip.h"
#include "Brig.h"
#include "Galleon.h"
#include "Schooner.h"
#include <iostream>


enum State{
    IDLE,
    SHOOTING,
    SHOT,
    DESTROYED
};

class Ship: public IShip
{
    public:
        Ship();
        virtual ~Ship();
        int getId() const override;
        void move() override;
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void recieveDamage(int amount) override;
        int getXPosition() const override;
        int getYPosition() const override;
        void setXPosition(int xPos) override;
        void setYPosition(int yPos) override;
        void attack(std::unique_ptr<IShip>& target) = 0;

    protected:
        int _hull;
        int _size;
        int _damage;
        int _id;
        bool _isAlive;
        State _state;

    private:
        int _posX;
        int _posY;


};

#endif // SHIP_H
