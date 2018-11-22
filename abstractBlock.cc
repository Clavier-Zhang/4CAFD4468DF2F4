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
        if (points[i] == p) {
            points.erase(this->points.begin()+i);
            return;
        }
    }
}

// getters
string AbstractBlock::getType() {
    return type;
}

std::vector<Point*>& AbstractBlock::getPoints() {
    return points;
}

bool AbstractBlock::addPoint(pair<int, int> &c, AbstractPlayer *p) {
    if (p->getPoint(c)->getType() != " ") return false;
    p->getPoint(c)->setType(this->type);
    this->points.emplace_back(p->getPoint(c));
    return true;
}

void AbstractBlock::addPoints(vector<pair<int, int>>& coordinates, AbstractPlayer *p) {
        for (pair<int, int> c : coordinates) {
            this->addPoint(c, p);
        }
}

pair<int, int> AbstractBlock::getLowerLeft() {
 int minX = points.at(0)->getX();
 int maxY = points.at(0)->getY();
 for (Point *p : points) {
    if (p->getX() < minX) {
     minX = p->getX();
     }
    if (p->getY() > maxY) {
     maxY = p->getY();
     }
  }
  pair<int, int> lowerLeft = make_pair(minX, maxY);
  return lowerLeft;
}


int AbstractBlock::getScore() {
    return score;
}
