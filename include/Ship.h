#ifndef SHIP_H
#define SHIP_H
#include "IShip.h"
#include "Dice.h"



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
        std::string getTexturePath() override;
        std::string resolveFileName();
        State getState() const override;
        void setState(State state) override;

    protected:
        int _hull;
        int _size;
        int _damage;
        int _id;
        bool _isAlive;
        State _state;
        std::string _texturePath;

    private:
        int _x;
        int _y;
        int _xBorder;
        int _yBorder;
        std::unique_ptr<IController> _controller;


};

#endif // SHIP_H
