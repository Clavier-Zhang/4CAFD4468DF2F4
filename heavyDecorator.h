#ifndef _HEAVYDECORATOR_H_
#define _HEAVYDECORATOR_H_
#include "abstractDecorator.h"
class HeavyDecorator : public AbstractDecorator {
    public:
        HeavyDecorator(AbstractPlayer *absPlayer );
        // player's operation
        // check if it is possible to level up/down
        void setLevel(int level);
        // add the points of blocks to grid, update the block in drop(), 
        void drop();
};
#endif
