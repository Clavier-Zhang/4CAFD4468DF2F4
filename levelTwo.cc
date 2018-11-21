#include "abstractBlock.h"
#include "levelTwo.h"
#include "abstractLevel.h"
#include "blockX.h"
using namespace std;

LevelTwo::LevelTwo() : AbstractLevel{2, "", false} {}
LevelTwo::~LevelTwo() {}
 
AbstractBlock* LevelTwo::generateBlock() {
    return new BlockX();
}
