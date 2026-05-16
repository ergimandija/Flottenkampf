#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#include "PlayerController.h"
#include "IController.h"
class PlayerController: public IController
{
    public:
        PlayerController();
        virtual ~PlayerController();
        char pickMovement() override;
        int pickTarget() override;

    protected:

    private:
};

#endif // PLAYERCONTROLLER_H
