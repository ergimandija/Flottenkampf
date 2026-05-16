#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#include <iostream>

class IController
{
    public:
        IController();
        virtual ~IController();
        virtual int pickTarget() = 0;
        virtual char pickMovement() = 0;

    protected:

    private:
};

#endif // ICONTROLLER_H
