#ifndef SHIP_H
#define SHIP_H
#include "IShip.h"
#include "Dice.h"

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
        void setId(int id) override;
        void move() override;
        Ship(int x,int y);
        bool isAlive();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        bool recieveDamage(int amount, int rolledAmount) override;
        int getXPosition() const override;
        int getYPosition() const override;
        void setXPosition(int xPos) override;
        void setYPosition(int yPos) override;
        void attack(std::unique_ptr<IShip>& target) = 0;
        void setController(std::unique_ptr<IController>& controller);
        std::unique_ptr<IController>& getController() override;
        virtual std::string getTexturePath() override;
    protected:
        int _hull;
        int _size;
        int _damage;
        int _id;
        bool _isAlive;
        State _state;
        std::string _texturePath;

    private:
        int _posX;
        int _posY;
        std::unique_ptr<IController> _controller;


};

#endif // SHIP_H
