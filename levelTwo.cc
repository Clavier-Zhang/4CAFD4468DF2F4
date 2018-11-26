#include "abstractBlock.h"
#include "levelTwo.h"
#include "abstractLevel.h"
#include "blockI.h"
#include "blockJ.h"
#include "blockL.h"
#include "blockO.h"
#include "blockS.h"
#include "blockT.h"
#include "blockZ.h"
using namespace std;

LevelTwo::LevelTwo() : AbstractLevel{2, "", false} {}
LevelTwo::~LevelTwo() {}
 
AbstractBlock* LevelTwo::generateBlock(char type) {
    if (type != ' ') return createCustomBlock(type);
    const double DEFAULT = 1/7;
    char c = this->generateChar(DEFAULT,DEFAULT,DEFAULT,DEFAULT,
    DEFAULT,DEFAULT,DEFAULT);
    return createCustomBlock(c);
}
