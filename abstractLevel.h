#ifndef _ABSTRACTLEVEL_H_
#define _ABSTRACTLEVEL_H_
#include <vector>
#include <string>
#include <iostream>
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
        char generateChar(double bI, double bJ,double bL, double bT, double bS, 
        double bZ, double bO);
    public:
        AbstractLevel(int level, std::string sequence, bool isRandom );
        ~AbstractLevel();
        virtual AbstractBlock* generateBlock(char type = ' ') = 0;
        AbstractBlock *createCustomBlock(char);
        // getter
        int getLevel();
};
#endif
