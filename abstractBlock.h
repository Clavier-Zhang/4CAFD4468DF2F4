#ifndef _ABSTRACTBLOCK_H_
#define _ABSTRACTBLOCK_H_
#include "window.h"
#include "abstractLevel.h"
// visitable
class AbstractBlock {
    // set protected, so can be called in concrete block and draw
    protected:
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
};
#endif