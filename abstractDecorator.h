#ifndef _ABSTRACTDECORATOR_H_
#define _ABSTRACTDECORATOR_H_
#include "abstractPlayer.h"

class AbstractDecorator : public AbstractPlayer {
    protected:
        AbstractPlayer *player;
        AbstractDecorator(AbstractPlayer *, Game * );
//        AbstractLevel * getLevel();// TODO: fix later
};
#endif
