#include "blockI.h"
#include "abstractLevel.h"
#include "point.h"
using namespace std;

BlockI::BlockI()
    : AbstractBlock{"I"} {}

void BlockI::addPoint(Point *p) {
    p->setType(this->type);
    this->points.emplace_back(p);
}
