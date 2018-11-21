#include "blockI.h"
#include "abstractPlayer.h"
#include "point.h"
#include "coordinate.h"
using namespace std;

BlockI::BlockI(int score) : AbstractBlock{"I", score} {
    Coordinate c1{0,3};
    Coordinate c2{1,3};
    Coordinate c3{2,3};
    Coordinate c4{3,3};
    this->positions.emplace_back(c1);
    this->positions.emplace_back(c2);
    this->positions.emplace_back(c3);
    this->positions.emplace_back(c4);
}

BlockI::~BlockI() {}

// initialize, only call once for each block
void BlockI::initialize(AbstractPlayer *p) {
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
