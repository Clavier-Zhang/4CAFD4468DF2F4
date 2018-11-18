#ifndef _BLOCK_I_
#define _BLOCK_I_
#include "abstractBlock.h"
#include <string>
#include <vector>
#include "point.h"
#include "abstractLevel.h"
#include <memory>
class BlockI : public AbstractBlock {
    public:
        BlockI();
        // accept for visitor pattern
        void accept(class AbstractLevel &level) override;
        // simple implementation
        // {
        //      level.generateBlock(this);
        // }
};
#endif