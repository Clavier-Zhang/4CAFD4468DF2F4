#include "blockI.h"
#include "abstractPlayer.h"
#include "point.h"
#include "coordinate.h"
using namespace std;

BlockI::BlockI() : AbstractBlock{"I"} {
    Coordinate c1{0,1};
    Coordinate c2{1,1};
    Coordinate c3{2,1};
    Coordinate c4{3,1};
    this->positions.emplace_back(c1);
    this->positions.emplace_back(c2);
    this->positions.emplace_back(c3);
    this->positions.emplace_back(c4);
}

// initialize, only call once for each block
void BlockI::initialize(AbstractPlayer *p) {
    // get point pointers
    for (Coordinate &c : this->positions) {
        this->addPoint(c, p);
    }
    // set points
    for (Point *p : this->points) {
        p->setType(this->type);
    }
}
