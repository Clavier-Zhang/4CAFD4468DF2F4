#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_
#include <string>
#include "abstractLevel.h"
#include "abstractBlock.h"
class LevelTwo : public AbstractLevel {
    public:
        LevelTwo();
        ~LevelTwo();
        AbstractBlock* generateBlock() override;

};
#endif