#include <string>
#include "abstractBlock.h"
#include "abstractPlayer.h"
#include "point.h"
#include <iostream>
#include <vector>
using namespace std;

AbstractBlock::AbstractBlock(string type) : type{type} {}

string AbstractBlock::getType() {
    return this->type;
}

void AbstractBlock::removePoint(Point *p) {
    p->setType(" ");
    for (int i = 0; i < this->points.size(); i++) {
        if (this->points[i] == p) {
            this->points.erase(this->points.begin() + i);
            return;
        }
    }
}

void AbstractBlock::removeAllPoint() {
    this->points.clear();
}

void AbstractBlock::addPoint(Coordinate &c, AbstractPlayer *p) {
    this->points.emplace_back(p->getPoint(c));
}