#ifndef _BLINDDECORATOR_H_
#define _BLINDDECORATOR_H_
#include "abstractDecorator.h"
class BlindDecorator : public AbstractDecorator {
    public:
        BlindDecorator(AbstractPlayer *, Game *g);
        // player's operation
        // check if it is possible to level up/down
        void setLevel(int level);
        // add the points of blocks to grid, update the block in drop(), 
        void drop() override;

        void rotate(bool, int) override;

        bool move(std::string, int) override;

        void setRandom() override;

        void setCurrentBlock(char) override;

        std::string getGridRow(int) override;



};
#endif
