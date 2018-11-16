#ifndef _ABSTRACTBLOCK_H_
#define _ABSTRACTBLOCK_H_
#include <iostream>
#include "window.h"
#include "abstractLevel.h"
#include "point.h"
// visitable
class AbstractBlock {
    // set protected, so can be called in concrete block and draw
    protected:
        // have four points in the vector
        // each time we move or rotate block, 
        // we edit the points in the vector
        std::vector<Point> points;
        // determined by level
        bool is_heavy = false;
        // window
        Window* xw;
    public:
        // user operation
        virtual void moveLeft() = 0;
        virtual void moveRight() = 0;
        virtual void moveDown() = 0;
        virtual void rotateClockwise() = 0;
        virtual void rotateCounterClockwise() = 0;
        // accept
        virtual void accept(AbstractLevel &level) = 0;
        // display, not sure which pattern it is
        // put draw here to reduce workload
        void draw();
        void undraw();
        // getter/setter, so we do not need friend
        std::vector<Point> getPoints();
};
std::ostream& operator<<(std::ostream &out, const AbstractBlock &p);
#endif