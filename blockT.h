#ifndef _BLOCK_T_
#define _BLOCK_T_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include "point.h"
#include "abstractLevel.h"
class BlockT : public AbstractBlock {
    public:
        // constructor, put points into vectors, 
        // set the string/color of point
        // according to the block feature
        // maybe multiple constructor
        BlockT();
        void catchPoints(AbstractPlayer *p) override;
};
#endif