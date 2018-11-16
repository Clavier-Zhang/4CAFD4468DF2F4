#ifndef _BLOCK_I_
#define _BLOCK_I_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include "point.h"
#include "abstractLevel.h"
class BlockI : public AbstractBlock {
    private:
        // have four points in the vector
        // each time we move or rotate block, 
        // we edit the points in the vector
        std::vector<Point> points;
        // determined by level
        bool is_heavy = false;
    public:
        // constructor, put points into vectors, 
        // set the string/color of point
        // according to the block feature
        // maybe multiple constructor
        BlockI();
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