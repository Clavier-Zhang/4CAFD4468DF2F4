#include "blindDecorator.h"
#include "abstractDecorator.h"
using namespace std;

BlindDecorator::BlindDecorator(AbstractDecorator *abstractDecorator) {}
// player's operation
// check if it is possible to level up/down
void BlindDecorator::setLevel(int level) {}
// check if it's movable, then call block's method to move
void BlindDecorator::moveLeft(int step) {}
void BlindDecorator::moveRight(int step) {}
void BlindDecorator::moveDown(int step) {}
void BlindDecorator::rotateClockwise() {}
void BlindDecorator::rotateCounterClockwise() {}
// add the points of blocks to grid, update the block in drop(), 
void BlindDecorator::drop() {}