#include "blockJ.h"
#include "abstractLevel.h"
#include "abstractPlayer.h"
using namespace std;

BlockJ::BlockJ(int score) : AbstractBlock{"J", score} {
    Coordinate c1{0,3};
    Coordinate c2{1,3};
    Coordinate c3{2,3};
    Coordinate c4{0,2};
    this->positions.emplace_back(c1);
    this->positions.emplace_back(c2);
    this->positions.emplace_back(c3);
    this->positions.emplace_back(c4);
}

BlockJ::~BlockJ() {}

// initialize, only call once for each block
void BlockJ::initialize(AbstractPlayer *p) {
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
