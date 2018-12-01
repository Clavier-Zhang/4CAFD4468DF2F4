#ifndef _LEVELONE_H_
#define _LEVELONE_H_
#include <string>
#include "abstractLevel.h"
class AbstractBlock;
class LevelOne : public AbstractLevel {
    public:
        LevelOne();
        ~LevelOne();
        AbstractBlock* generateBlock(char type = ' ') override;
};
#endif
