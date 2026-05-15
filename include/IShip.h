#ifndef ISHIP_H
#define ISHIP_H
#include <memory>

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
        virtual void recieveDamage(int amount) = 0;
        virtual bool isAlive()  = 0;

    protected:

    private:
};

#endif // ISHIP_H
