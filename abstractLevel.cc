#include "abstractLevel.h"
#include <cstdlib>
#include "blockI.h"
#include "blockJ.h"
#include "blockL.h"
#include "blockO.h"
#include "blockS.h"
#include "blockT.h"
#include "blockZ.h"
#include "blockX.h"

using namespace std;

AbstractLevel::AbstractLevel(int level, std::string sequence, bool isRandom )
    : level{level}, sequence{sequence}, isRandom{isRandom} {}

AbstractLevel::~AbstractLevel() {}

char AbstractLevel::generateChar(double bI, double bJ,double bL, double bT, double bS, double bZ, double bO){
    double prob= ((double)rand()/(RAND_MAX));
    double intv=bI;
    if (prob <= intv){
        return 'I';
    }
    intv+=bJ;

    if ( prob<=intv){
        return 'J';
    }
    intv+=bL;

    if ( prob<= intv){
        return 'L';
    }
    intv+=bT;
    
    if (prob <= intv){
        return 'T';
    }
    intv+=bS;

    if ( prob <= intv){
        return 'S';
    }

    intv+= bZ;

    if (prob <= intv){
        return 'Z';
    }

    return 'O';
}

int AbstractLevel::getLevel() {
    return this->level;
}

AbstractBlock* AbstractLevel::createCustomBlock(char type) {
    switch (type) {
     case 'I': return new BlockI((level + 1) * (level + 1));
     case 'J': return new BlockJ((level + 1) * (level + 1));
     case 'L': return new BlockL((level + 1) * (level + 1));
     case 'T': return new BlockT((level + 1) * (level + 1));
     case 'O': return new BlockO((level + 1) * (level + 1));
     case 'S': return new BlockS((level + 1) * (level + 1));
     case 'X': return new BlockX((level + 1) * (level + 1));
     default: return new BlockZ((level + 1) * (level + 1));
     }
}
