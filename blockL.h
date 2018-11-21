#ifndef _BLOCK_L_
#define _BLOCK_L_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include "point.h"
#include "abstractLevel.h"
class BlockL : public AbstractBlock {
    public:
        // constructor, put points into vectors, 
        // set the string/color of point
        // according to the block feature
        // maybe multiple constructor
        BlockL();
        void initialize(AbstractPlayer *p) override;
};
#endif