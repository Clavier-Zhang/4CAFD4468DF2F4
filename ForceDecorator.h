#ifndef _FORCEDECORATOR_H_
#define _FORCEDECORATOR_H_
#include "abstractDecorator.h"
class ForceDecorator : public AbstractDecorator {
    public:
        ForceDecorator(AbstractDecorator *abstractDecorator);
        // player's operation
        // check if it is possible to level up/down
        void setLevel(int level);
        void rotateClockwise();
        void rotateCounterClockwise();
        // add the points of blocks to grid, update the block in drop(), 
        void drop();
};
#endif