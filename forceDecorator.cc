#include "forceDecorator.h"
#include "abstractDecorator.h"
using namespace std;

ForceDecorator::ForceDecorator(AbstractDecorator *abstractDecorator) {}
// player's operation
// check if it is possible to level up/down
void ForceDecorator::setLevel(int level) {}
void ForceDecorator::rotateClockwise() {}
void ForceDecorator::rotateCounterClockwise() {}
// add the points of blocks to grid, update the block in drop(), 
void ForceDecorator::drop() {}