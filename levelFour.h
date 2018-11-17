#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_
#include <string>
#include "AbstractLevel.h"
class LevelFour : public AbstractLevel {
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