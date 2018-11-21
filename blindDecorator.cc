#include "blindDecorator.h"
#include "abstractDecorator.h"
using namespace std;

BlindDecorator::BlindDecorator(AbstractDecorator *abstractDecorator) {}
// player's operation
// check if it is possible to level up/down
void BlindDecorator::setLevel(int level) {}
// add the points of blocks to grid, update the block in drop(), 
void BlindDecorator::drop() {}