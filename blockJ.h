#ifndef _BLOCK_J_
#define _BLOCK_J_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include "point.h"
#include "abstractLevel.h"
class BlockJ : public AbstractBlock {
    public:
        // constructor, put points into vectors, 
        // set the string/color of point
        // according to the block feature
        // maybe multiple constructor
        BlockJ(int score);
        ~BlockJ();
        void initialize(AbstractPlayer *p) override;
};
#endif
