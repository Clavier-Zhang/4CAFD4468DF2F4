#include "blockJ.h"
#include "abstractLevel.h"
#include "abstractPlayer.h"
using namespace std;

BlockJ::BlockJ() : AbstractBlock{"J"} {
}

BlockJ::~BlockJ() {}

// only for initialize
void BlockJ::initialize(AbstractPlayer *p) {
}