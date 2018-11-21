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
class AbstractPlayer;
// visitor
class AbstractLevel {
    protected:
        int level = 1;
        // set in the constructor, either from file or generate randomly
        std::string sequence;
        int seqAt = 0;
        // if is random mode, update sequence with one char each time
        bool isRandom = false;
    public:
        AbstractLevel(int level, std::string sequence, bool isRandom );
        ~AbstractLevel();
        virtual AbstractBlock* generateBlock() = 0;
        // getter
        int getLevel();
};
#endif