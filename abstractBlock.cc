#include <string>
#include "abstractBlock.h"
#include "abstractPlayer.h"
#include "point.h"
#include <iostream>
#include <vector>
using namespace std;

AbstractBlock::AbstractBlock(string type) : type{type} {}
AbstractBlock::~AbstractBlock() {}
bool AbstractBlock::contain(Point *p) {
    for (Point *old : this->points) {
        if (old == p) {
            return true;
        }
    }
    return false;
}

void AbstractBlock::removeAllPoint() {
    for (Point *p : this->points) {
        p->reset();
    }
    this->points.clear();
}

// getters
string AbstractBlock::getType() {
    return this->type;
}

std::vector<Point*>& AbstractBlock::getPoints() {
    return this->points;
}

void AbstractBlock::addPoint(Coordinate &c, AbstractPlayer *p) {
    p->getPoint(c)->setType(this->type);
    this->points.emplace_back(p->getPoint(c));
}

void AbstractBlock::addPoints(vector<Coordinate>& coordinates, AbstractPlayer *p) {
        for (Coordinate c : coordinates) {
            this->addPoint(c, p);
        }
}