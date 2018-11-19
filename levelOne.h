#ifndef _LEVELONE_H_
#define _LEVELONE_H_
#include <string>
#include "abstractLevel.h"
#include "abstractBlock.h"
class LevelOne : public AbstractLevel {
    public:
        // visitor 
        AbstractBlock* generateBlock() override;
    private:
        AbstractBlock* generateBlock(BlockI &b) override;
        AbstractBlock* generateBlock(BlockJ &b) override;
        AbstractBlock* generateBlock(BlockL &b) override;
        AbstractBlock* generateBlock(BlockO &b) override;
        AbstractBlock* generateBlock(BlockS &b) override;
        AbstractBlock* generateBlock(BlockT &b) override;
        AbstractBlock* generateBlock(BlockZ &b) override;
        AbstractBlock* generateBlock(BlockX &b) override;
};
#endif
