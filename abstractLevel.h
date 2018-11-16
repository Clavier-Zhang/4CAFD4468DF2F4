#ifndef _ABSTRACTLEVEL_H_
#define _ABSTRACTLEVEL_H_
#include "blockI.h"
#include "blockJ.h"
#include "blockL.h"
#include "blockO.h"
#include "blockS.h"
#include "blockT.h"
#include "blockZ.h"
// visitor
class AbstractLevel {
    public:
        // visitor 
        virtual void generateBlock(BlockI &b) = 0;
        virtual void generateBlock(BlockJ &b) = 0;
        virtual void generateBlock(BlockL &b) = 0;
        virtual void generateBlock(BlockO &b) = 0;
        virtual void generateBlock(BlockS &b) = 0;
        virtual void generateBlock(BlockT &b) = 0;
        virtual void generateBlock(BlockZ &b) = 0;
};
#endif