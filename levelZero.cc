#include "abstractBlock.h"
#include "levelZero.h"
#include "abstractLevel.h"
#include "blockI.h"
#include "blockJ.h"
#include "blockL.h"
#include "blockO.h"
#include "blockS.h"
#include "blockT.h"
#include "blockZ.h"
#include <string>

using namespace std;

LevelZero::LevelZero(string scpt) : AbstractLevel{0, "", false}, scpt{scpt} {
    setRandom(false, scpt);
};

LevelZero::~LevelZero() {}

AbstractBlock* LevelZero::generateBlock(char type) {
    if (type != ' ') return createCustomBlock(type);
    char c = nonRandomBlock();
    return createCustomBlock(c);
}
