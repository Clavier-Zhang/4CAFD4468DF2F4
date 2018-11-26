#ifndef _FORCEDECORATOR_H_
#define _FORCEDECORATOR_H_
#include "abstractDecorator.h"
class ForceDecorator : public AbstractDecorator {
        char forcedBlock;
    public:
        ForceDecorator(AbstractPlayer *, Game *);
        // player's operation
        // check if it is possible to level up/down
        void setLevel(int level) override;
        // add the points of blocks to grid, update the block in drop(), 
        bool move(std::string type, int step = 1) override;
        void rotate(bool counter = false, int step = 1) override;
        // add the points of blocks to grid, update the block in drop(), 
        void drop() override;
        // assign the point pointer to currentBlock, can
        void setRandom() override;
        // display
        void setCurrentBlock(char type = ' ') override;
};
#endif
