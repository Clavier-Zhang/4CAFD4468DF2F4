#include "blockZ.h"
#include "abstractLevel.h"
#include "abstractPlayer.h"
using namespace std;

BlockZ::BlockZ(int score) : AbstractBlock{"Z", score} {
    Coordinate c1{0,2};
    Coordinate c2{1,2};
    Coordinate c3{1,3};
    Coordinate c4{2,3};
    this->positions.emplace_back(c1);
    this->positions.emplace_back(c2);
    this->positions.emplace_back(c3);
    this->positions.emplace_back(c4);
}

BlockZ::~BlockZ() {}

// initialize, only call once for each block
void BlockZ::initialize(AbstractPlayer *p) {
    // get point pointers
    for (Coordinate &c : this->positions) {
        if (!this->addPoint(c, p)) {
            p->notifyGameover();
            return;
        }
    }
    // set points
    for (Point *p : this->points) {
        p->setType(this->type);
    }
}
