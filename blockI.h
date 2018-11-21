#ifndef _BLOCK_I_
#define _BLOCK_I_
#include <vector>
#include <memory>
#include "abstractBlock.h"
class AbstractPlayer;
class BlockI : public AbstractBlock {
    public:
        BlockI(int score);
        ~BlockI();
        void initialize(AbstractPlayer *p) override;
};
#endif
