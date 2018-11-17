#ifndef _ABSTRACTBLOCK_H_
#define _ABSTRACTBLOCK_H_
#include <iostream>
#include "window.h"
#include "abstractLevel.h"
#include "point.h"
#include <string>
// visitable
class AbstractBlock {
    // set protected, so can be called in concrete block and draw
    protected:
        // have four points in the vector
        // each time we move or rotate block, 
        // we edit the points in the vector
        std::vector<Point> points;
        std::string type;
    public:
        // accept
        virtual void accept(AbstractLevel &level) = 0;
};
#endif