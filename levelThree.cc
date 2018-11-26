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

LevelThree::LevelThree() : AbstractLevel{3, "", true} {} 

LevelThree::~LevelThree() {}

AbstractBlock* LevelThree::generateBlock(char type) {
    if (type != ' ') return createCustomBlock(type);
    const double DEFAULT = 1/9;
    const double Z_S_PROB = 2/9;
    char c = generateChar(DEFAULT,DEFAULT,DEFAULT,DEFAULT,
    Z_S_PROB,Z_S_PROB,DEFAULT);
    return createCustomBlock(c);
}
