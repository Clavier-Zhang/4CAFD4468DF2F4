#include "blockI.h"
#include "abstractPlayer.h"
#include "point.h"
using namespace std;

BlockI::BlockI(int score) : AbstractBlock{"I", score} {
    auto c1 = make_pair(0, 3);
    auto c2 = make_pair(1, 3);
    auto c3 = make_pair(2, 3);
    auto c4 = make_pair(3, 3);
    positions.emplace_back(c1);
    positions.emplace_back(c2);
    positions.emplace_back(c3);
    positions.emplace_back(c4);
}

BlockI::~BlockI() {}

// initialize, only call once for each block
void BlockI::initialize(AbstractPlayer *p) {
    // get point pointers
     for (pair<int, int> &c : positions) {
        if (!addPoint(c, p)) {
            p->notifyGameover();
            return;
        }
    }
    // set points
    for (Point *p : points) {
        p->setType(type);

    }
}
