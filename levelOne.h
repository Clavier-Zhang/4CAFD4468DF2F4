#ifndef _LEVELONE_H_
#define _LEVELONE_H_
#include <string>
#include "abstractLevel.h"
#include "abstractBlock.h"
class LevelOne : public AbstractLevel {
    public:
        LevelOne();
        ~LevelOne();
        AbstractBlock* generateBlock() override;
};
#endif
