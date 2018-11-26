//#include "abstractBlock.h"
#include "levelOne.h"
#include "abstractLevel.h"


using namespace std;

LevelOne::LevelOne() : AbstractLevel{1, "", true} {
};

LevelOne::~LevelOne() {}

AbstractBlock * LevelOne::generateBlock(char type){
    if (type != ' ') return createCustomBlock(type);
    const double DEFAULT = 1/6;
    const double Z_S_PROB = 1/12;
    char c = this->generateChar(DEFAULT,DEFAULT,DEFAULT,DEFAULT,
    Z_S_PROB,Z_S_PROB,DEFAULT);
    return createCustomBlock(c);
}
