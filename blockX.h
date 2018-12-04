#ifndef _BLOCK_X_
#define _BLOCK_X_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include "point.h"
#include "abstractLevel.h"
class BlockX : public AbstractBlock {
    public:
        BlockX(int score);
        ~BlockX();
        void initialize(AbstractPlayer *p) override;
};
#endif
