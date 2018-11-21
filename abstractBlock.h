#ifndef _ABSTRACTBLOCK_H_
#define _ABSTRACTBLOCK_H_
#include <string>
#include <vector>
#include "coordinate.h"
class AbstractLevel;
class Point;
class AbstractPlayer;
class AbstractBlock {
    // set protected, so can be called in concrete block and draw
    protected:
        // have four points in the vector
        // each time we move or rotate block, 
        // we edit the points in the vector
        std::vector<Point*> points;
        std::string type;
        // 4 pairs of number to store init positions
        std::vector<Coordinate> positions;
    public:
        AbstractBlock(std::string type);
        virtual void initialize(AbstractPlayer *p) = 0;
        void addPoint(Coordinate &c, AbstractPlayer *p);
        void addPoints(std::vector<Coordinate>& coordinates, AbstractPlayer *p);
        void removeAllPoint();
        std::string getType();
        std::vector<Point*>& getPoints();
        bool contain(Point *p);
};
#endif
