#ifndef _BLOCK_Z_
#define _BLOCK_Z_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include "point.h"
#include "abstractLevel.h"
class BlockZ : public AbstractBlock {
    public:
        // constructor, put points into vectors, 
        // set the string/color of point
        // according to the block feature
        BlockZ();
        void initialize(AbstractPlayer *p) override;
};
#endif