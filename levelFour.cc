#include "abstractBlock.h"
#include "levelFour.h"
#include "blockI.h"
#include "blockJ.h"
#include "blockL.h"
#include "blockO.h"
#include "blockS.h"
#include "blockT.h"
#include "blockZ.h"
using namespace std;

LevelFour::LevelFour(): AbstractLevel{4, "", true}{} 


LevelFour::~LevelFour() {}


AbstractBlock* LevelFour::generateBlock(char type) {
    if (type != ' ') return createCustomBlock(type);
    char c;
    if (isRandom){
        const double DEFAULT = static_cast<double>(1)/9;
        const double Z_S_PROB = static_cast<double>(2)/9;
        c = this->generateChar(DEFAULT,DEFAULT,DEFAULT,DEFAULT,
                Z_S_PROB,Z_S_PROB,DEFAULT);
    }else{
        c = nonRandomBlock();
    }
    return createCustomBlock(c);
}


int LevelFour::getNumUncleared()const{
    return numUncleared;
}


void LevelFour::incNumUncleared(){
    numUncleared++;
}


void LevelFour::resetNumUncleared(){
    numUncleared = 0;
}

