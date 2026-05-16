#ifndef ISHIP_H
#define ISHIP_H
#include <memory>
#include "IController.h"
#include <iostream>

class IShip
{
    public:
        IShip();
        virtual ~IShip();
        virtual int getId() const = 0;
        virtual void setId(int id) = 0;
        virtual void attack(std::unique_ptr<IShip>& target) = 0;
        virtual void move() = 0;
        virtual int getXPosition() const = 0;
        virtual int getYPosition() const = 0;
        virtual void setXPosition(int xPos) = 0;
        virtual void setYPosition(int yPos) = 0;
        virtual bool recieveDamage(int amount, int rolledAmount) = 0;
        virtual bool isAlive()  = 0;
        virtual std::string getTexturePath() const = 0;
        virtual std::unique_ptr<IController>& getController() = 0;

    protected:

    private:
};

#endif // ISHIP_H
