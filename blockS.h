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
        BlockS(int score);
        ~BlockS();
        void initialize(AbstractPlayer *p) override;
};
#endif