#include "blockX.h"
#include "abstractLevel.h"
#include "abstractPlayer.h"
using namespace std;

BlockX::BlockX(int score) : AbstractBlock{"X", score} {
}

BlockX::~BlockX() {}

void BlockX::initialize(AbstractPlayer *p) {
    // get point pointers
    string row;
    for (int i = 17; i > 2; i--){

        row = p->getGridRow(i);
        if (row[5] == ' '){
            auto c1 = make_pair(5,i);
            positions.emplace_back(c1);
            break;
        }

    }
    if ((int)positions.size() == 0){
        p->notifyGameover();
        return;
    }

     for (pair<int, int> &c : positions) {
        addPoint(c, p);
    }
    // set points
    for (Point *p : this->points) {
        p->setType(this->type);
    }
}
