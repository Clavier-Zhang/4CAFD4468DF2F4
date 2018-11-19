#include "blockI.h"
#include "abstractLevel.h"
using namespace std;

BlockI::BlockI()
    : AbstractBlock{"I"} {}
    
void BlockI::accept(AbstractLevel &level) {}
