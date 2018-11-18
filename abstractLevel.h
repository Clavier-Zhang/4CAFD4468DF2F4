#ifndef _ABSTRACTLEVEL_H_
#define _ABSTRACTLEVEL_H_
#include <vector>
#include <string>
class Point;
class AbstractBlock;
class BlockI;
class BlockJ;
class BlockL;
class BlockO;
class BlockS;
class BlockT;
class BlockZ;
class BlockX;
// #include "blockI.h"
// #include "blockJ.h"
// #include "blockL.h"
// #include "blockO.h"
// #include "blockS.h"
// #include "blockT.h"
// #include "blockZ.h"
// #include "blockX.h"
class AbstractPlayer;
// #include "abstractPlayer.h"
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