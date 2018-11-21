#include "blockZ.h"
#include "abstractLevel.h"
#include "abstractPlayer.h"
using namespace std;

BlockZ::BlockZ(int score) : AbstractBlock{"Z", score} {
/*    Coordinate c1{0,2};
    Coordinate c2{1,2};
    Coordinate c3{1,3};
    Coordinate c4{2,3};*/

    auto c1 = make_pair(0, 2);
    auto c2 = make_pair(1, 2);
    auto c3 = make_pair(1, 3);
    auto c4 = make_pair(2, 3);
    positions.emplace_back(c1);
    positions.emplace_back(c2);
    positions.emplace_back(c3);
    positions.emplace_back(c4);
}

BlockZ::~BlockZ() {}

// initialize, only call once for each block
void BlockZ::initialize(AbstractPlayer *p) {
    // get point pointers
    //for (Coordinate &c : this->positions) {
     for (pair<int, int> &c : positions) {
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
