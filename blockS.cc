#include "blockS.h"
#include "abstractLevel.h"
#include "abstractPlayer.h"
using namespace std;

BlockS::BlockS(int score) : AbstractBlock{"S", score} {
    Coordinate c1{0,3};
    Coordinate c2{1,3};
    Coordinate c3{1,2};
    Coordinate c4{2,2};
    this->positions.emplace_back(c1);
    this->positions.emplace_back(c2);
    this->positions.emplace_back(c3);
    this->positions.emplace_back(c4);
}

BlockS::~BlockS() {}

// initialize, only call once for each block
void BlockS::initialize(AbstractPlayer *p) {
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
