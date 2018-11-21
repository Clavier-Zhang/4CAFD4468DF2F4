#include "abstractBlock.h"
#include "levelOne.h"
#include "abstractLevel.h"
#include "blockI.h"
using namespace std;

LevelOne::LevelOne() : AbstractLevel{1, "", false} {};

LevelOne::~LevelOne() {}

AbstractBlock* LevelOne::generateBlock() {
    return new BlockI(this->level * this->level);
}