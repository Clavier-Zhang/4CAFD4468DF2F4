//#include "abstractBlock.h"
#include "levelOne.h"
#include "abstractLevel.h"
#include "blockI.h"
#include "blockJ.h"
#include "blockL.h"
#include "blockO.h"
#include "blockS.h"
#include "blockT.h"
#include "blockZ.h"


using namespace std;

LevelOne::LevelOne() : AbstractLevel{1, "", true} {
};

LevelOne::~LevelOne() {}

AbstractBlock * LevelOne::generateBlock(){
    const double DEFAULT = 1/6;
    double Z_S_PROB = 1/12;
    char c = this->generateChar(DEFAULT,DEFAULT,DEFAULT,DEFAULT,
    Z_S_PROB,Z_S_PROB,DEFAULT);
    if (c == 'I') {
        return new BlockI((this->level + 1) * (this->level + 1));
    }else if (c == 'J') {
        return new BlockJ((this->level + 1) * (this->level + 1));
    }else if (c == 'L') {
        return new BlockL((this->level + 1) * (this->level + 1));
    }else if (c == 'O') {
        return new BlockO((this->level + 1) * (this->level + 1));
    }else if (c == 'S') {
        return new BlockS((this->level + 1) * (this->level + 1));
    }else if (c == 'T') {
        return new BlockT((this->level + 1) * (this->level + 1));
    }else { // has to be Z
        return new BlockZ((this->level + 1) * (this->level + 1));
    }

}
