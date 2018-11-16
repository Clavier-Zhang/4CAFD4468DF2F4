#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_
#include <string>
#include "AbstractLevel.h"

class LevelThree : public AbstractLevel {
    public:
        // visitor 
        void generateBlock(BlockI &b) override;
        void generateBlock(BlockJ &b) override;
        void generateBlock(BlockL &b) override;
        void generateBlock(BlockO &b) override;
        void generateBlock(BlockS &b) override;
        void generateBlock(BlockT &b) override;
        void generateBlock(BlockZ &b) override;
};
#endif