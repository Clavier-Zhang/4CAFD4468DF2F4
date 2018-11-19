#include "abstractBlock.h"
#include "levelTwo.h"
#include "abstractLevel.h"
using namespace std;

LevelTwo::LevelTwo() : AbstractLevel{2, "", false} {}
LevelTwo::~LevelTwo() {}
 
AbstractBlock* LevelTwo::generateBlock() {
    return nullptr;
}
