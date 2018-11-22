#include "blockL.h"
#include "abstractLevel.h"
#include "abstractPlayer.h"
using namespace std;

BlockL::BlockL(int score) : AbstractBlock{"L", score} {
    auto c1 = make_pair(0, 3);
    auto c2 = make_pair(1, 3);
    auto c3 = make_pair(2, 3);
    auto c4 = make_pair(2, 2);

    this->positions.emplace_back(c1);
    this->positions.emplace_back(c2);
    this->positions.emplace_back(c3);
    this->positions.emplace_back(c4);
}

BlockL::~BlockL() {}

// initialize, only call once for each block
void BlockL::initialize(AbstractPlayer *p) {
    // get point pointers
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
