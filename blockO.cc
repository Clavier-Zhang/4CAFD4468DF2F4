#include "blockO.h"
#include "abstractLevel.h"
#include "abstractPlayer.h"
using namespace std;

BlockO::BlockO(int score) : AbstractBlock{"O", score} {
/*    Coordinate c1{0,3};
    Coordinate c2{1,3};
    Coordinate c3{1,2};
    Coordinate c4{0,2};*/

    auto c1 = make_pair(0, 3);
    auto c2 = make_pair(1, 3);
    auto c3 = make_pair(1, 2);
    auto c4 = make_pair(0, 2);
    positions.emplace_back(c1);
    positions.emplace_back(c2);
    positions.emplace_back(c3);
    positions.emplace_back(c4);
}

BlockO::~BlockO() {}

// initialize, only call once for each block
void BlockO::initialize(AbstractPlayer *p) {
    // get point pointers
//    for (Coordinate &c : this->positions) {
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
