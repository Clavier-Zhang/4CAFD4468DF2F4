#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include <string>
#include "abstractLevel.h"
#include "abstractBlock.h"
class LevelZero : public AbstractLevel {
    std::string scpt;//script used to generate blocks for the level
    public:
        LevelZero(std::string scpt);
        ~LevelZero();
        AbstractBlock* generateBlock(char type = ' ') override;
};
#endif
