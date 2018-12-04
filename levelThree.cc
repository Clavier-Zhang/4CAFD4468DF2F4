#include "abstractBlock.h"
#include "levelThree.h"
#include "blockI.h"
#include "blockJ.h"
#include "blockL.h"
#include "blockO.h"
#include "blockS.h"
#include "blockT.h"
#include "blockZ.h"
using namespace std;

LevelThree::LevelThree(): AbstractLevel{3, "", true}{} 


LevelThree::~LevelThree() {}


AbstractBlock* LevelThree::generateBlock(char type) {
    if (type != ' ') return createCustomBlock(type);
    char c;
    if(isRandom){
        const double DEFAULT = static_cast<double>(1)/9;
        const double Z_S_PROB = static_cast<double>(2)/9;
        c = generateChar(DEFAULT,DEFAULT,DEFAULT,DEFAULT,
        Z_S_PROB,Z_S_PROB,DEFAULT);
    }else{
        c = nonRandomBlock();
    }
    return createCustomBlock(c);
}
