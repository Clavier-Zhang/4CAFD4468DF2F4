#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_
#include <string>
#include "abstractLevel.h"
#include "abstractBlock.h"
class LevelFour : public AbstractLevel {
    public:
        ~LevelFour();
        AbstractBlock* generateBlock(char type = ' ') override;
};
#endif
