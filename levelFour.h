#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_
#include <string>
#include "abstractLevel.h"
#include "abstractBlock.h"
class LevelFour : public AbstractLevel {
    int numUncleared=0; //total number of turns gone without clearing rows
    public:
        LevelFour();
        ~LevelFour();
        AbstractBlock* generateBlock(char type = ' ') override;
        int getNumUncleared() const;
        void incNumUncleared();
        void resetNumUncleared();
};
#endif
