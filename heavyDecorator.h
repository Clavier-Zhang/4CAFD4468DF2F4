#ifndef _HEAVYDECORATOR_H_
#define _HEAVYDECORATOR_H_
#include "abstractDecorator.h"
class HeavyDecorator : public AbstractDecorator {
    public:
        // player's operation
        // check if it is possible to level up/down
        void setLevel(int level);
        // check if it's movable, then call block's method to move
        void moveLeft(int step = 1);
        void moveRight(int step = 1);
        void moveDown(int step = 1);
        void rotateClockwise();
        void rotateCounterClockwise();
        // add the points of blocks to grid, update the block in drop(), 
        void drop();
};
#endif