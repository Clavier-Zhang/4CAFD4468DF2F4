#ifndef _ABSTRACTBLOCK_H_
#define _ABSTRACTBLOCK_H_
#include <string>
#include <vector>
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
    public:
        AbstractBlock(std::string type);
        virtual void catchPoints(AbstractPlayer *p) = 0;
        void removePoint(Point *p);
        void removeAllPoint();
        std::string getType();
};
#endif
