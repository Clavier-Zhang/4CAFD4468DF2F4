#ifndef _ABSTRACTLEVEL_H_
#define _ABSTRACTLEVEL_H_
#include "abstractBlock.h"
#include "point.h"
#include "blockI.h"
#include "blockJ.h"
#include "blockL.h"
#include "blockO.h"
#include "blockS.h"
#include "blockT.h"
#include "blockZ.h"
#include "blockX.h"
#include <memory>
#include "abstractPlayer.h"
// visitor
class AbstractLevel {
    protected:
        int level;
        // set in the constructor, either from file or generate randomly
        std::string sequence;
        // if is random mode, update sequence with one char each time
        bool isRandom = false;
    public:
        virtual AbstractBlock* generateBlock() = 0;
    private:
        // visitor
        virtual AbstractBlock* generateBlock(BlockI &b) = 0;
        virtual AbstractBlock* generateBlock(BlockJ &b) = 0;
        virtual AbstractBlock* generateBlock(BlockL &b) = 0;
        virtual AbstractBlock* generateBlock(BlockO &b) = 0;
        virtual AbstractBlock* generateBlock(BlockS &b) = 0;
        virtual AbstractBlock* generateBlock(BlockT &b) = 0;
        virtual AbstractBlock* generateBlock(BlockZ &b) = 0;
        virtual AbstractBlock* generateBlock(BlockX &b) = 0;
        // getter
        int getLevel();
};
#endif