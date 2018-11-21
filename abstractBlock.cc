#include <string>
#include "abstractBlock.h"
#include "abstractPlayer.h"
#include "point.h"
#include <iostream>
#include <vector>
using namespace std;

AbstractBlock::AbstractBlock(string type, int score) : type{type}, score{score} {}

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

void AbstractBlock::removeOnePoint(Point *p) {
    for (int i = 0; i < this->points.size(); i++) {
        if (this->points[i] == p) {
            this->points.erase(this->points.begin()+i);
            return;
        }
    }
}

// getters
string AbstractBlock::getType() {
    return this->type;
}

std::vector<Point*>& AbstractBlock::getPoints() {
    return this->points;
}

bool AbstractBlock::addPoint(Coordinate &c, AbstractPlayer *p) {
    if (p->getPoint(c)->getType() != " ") return false;
    p->getPoint(c)->setType(this->type);
    this->points.emplace_back(p->getPoint(c));
    return true;
}

void AbstractBlock::addPoints(vector<Coordinate>& coordinates, AbstractPlayer *p) {
        for (Coordinate c : coordinates) {
            this->addPoint(c, p);
        }
}

int AbstractBlock::getScore() {
    return this->score;
}