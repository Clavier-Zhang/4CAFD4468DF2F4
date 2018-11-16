#ifndef _BLOCK_S_
#define _BLOCK_S_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include "point.h"
#include "abstractLevel.h"
class BlockS : public AbstractBlock {
    public:
        // constructor, put points into vectors, 
        // set the string/color of point
        // according to the block feature
        // maybe multiple constructor
        BlockS();
        // we will check if it's movable in the player class
        // this means if we call the following method,
        // the block if always movable
        // remeber to draw in the following method
        void moveLeft() override;
        void moveRight() override;
        void moveDown() override;
        void rotateClockwise() override;
        void rotateCounterClockwise() override;
        // accept for visitor pattern
        void accept(AbstractLevel &level) override;
        // simple implementation
        // {
        //      level.generateBlock(this);
        // }
};
#endif