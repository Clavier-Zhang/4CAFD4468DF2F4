#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include <string>
#include "abstractLevel.h"
#include "abstractBlock.h"
class LevelZero : public AbstractLevel {
    public:
        LevelZero();
        ~LevelZero();
        AbstractBlock* generateBlock() override;
};
#endif
