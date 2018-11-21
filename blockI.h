#ifndef _BLOCK_I_
#define _BLOCK_I_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include <memory>
class Point;
class AbstractPlayer;
class BlockI : public AbstractBlock {
    public:
        BlockI();
        void catchPoints(AbstractPlayer *p) override;
};
#endif