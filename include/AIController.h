#ifndef AICONTROLLER_H
#define AICONTROLLER_H
#include "IController.h"

class AIController: public IController
{
    public:
        AIController();
        virtual ~AIController();
        char pickMovement() override;
        int pickTarget() override;

    protected:

    private:
};

#endif // AICONTROLLER_H
