#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_
#include <string>
#include "abstractLevel.h"
#include "abstractBlock.h"
class LevelTwo : public AbstractLevel {
    public:
        // visitor 
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