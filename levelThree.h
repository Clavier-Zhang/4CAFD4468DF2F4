#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_
#include <string>
#include "abstractLevel.h"
#include "abstractBlock.h"
class LevelThree : public AbstractLevel {
    public:
        LevelThree();
        ~LevelThree();
        void setRandom(bool newRand);
        AbstractBlock* generateBlock(char type = ' ') override;

};
#endif
