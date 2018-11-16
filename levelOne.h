#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_
#include <string>
#include "AbstractLevel.h"

class LevelOne : public AbstractLevel {
    private:
        int level;
        // set in the constructor, either from file or generate randomly
        std::string sequence;
        // if is random mode, update sequence with one char each time
        bool isRandom = false;
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