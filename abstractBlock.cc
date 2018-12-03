#include <string>
#include "abstractBlock.h"
#include "abstractPlayer.h"
#include "point.h"
#include <iostream>
#include <vector>
using namespace std;

int AbstractBlock::curId = 0; // Initialize static member curId

AbstractBlock::AbstractBlock(string type, int score) : type{type}, score{score} {}

AbstractBlock::~AbstractBlock() {
}

bool AbstractBlock::contain(Point *p) {
    for (Point *old : this->points) {
        if (old == p) {
            return true;
        }
    }
    return false;
}

void AbstractBlock::removeAllPoint(bool isBlind) {
    for (Point *p : this->points) {
        p->reset(isBlind);
    }
    this->points.clear();
}

void AbstractBlock::removeOnePoint(Point *p) {
    for (int i = 0; i < (int)this->points.size(); i++) {
        if (points[i] == p) {
            points.erase(this->points.begin()+i);// should we set type to empty string?
            return;
        }
    }
}

void AbstractBlock::setID(int id){
    for (int i = 0; i < (int) points.size(); i++){
        points[i]->setID(id);
    }
}

// getters
string AbstractBlock::getType() {
    return type;
}

vector<std::pair<int, int>> & AbstractBlock::getPositions() {
    return this->positions;
}

std::vector<Point*>& AbstractBlock::getPoints() {
    return points;
}

bool AbstractBlock::addPoint(pair<int, int> &c, AbstractPlayer *p, bool isBlind) {
    if (p->getPoint(c)->getType() != " ") return false;
    p->getPoint(c)->setType(this->type, isBlind);
    this->points.emplace_back(p->getPoint(c));
    return true;// add ID aswell
}

void AbstractBlock::addPoints(vector<pair<int, int>>& coordinates, AbstractPlayer *p, bool isBlind) {
        for (pair<int, int> c : coordinates) {
            this->addPoint(c, p, isBlind);
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

int AbstractBlock::getCurId() { 
 return AbstractBlock::curId;
}

void AbstractBlock::incrementCurId() {
 ++AbstractBlock::curId;
}

