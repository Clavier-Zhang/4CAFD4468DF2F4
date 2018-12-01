#ifndef _ABSTRACTDECORATOR_H_
#define _ABSTRACTDECORATOR_H_
#include "abstractPlayer.h"
#include <memory>
class AbstractDecorator : public AbstractPlayer {
    protected:
        std::shared_ptr<AbstractPlayer> player;
        AbstractDecorator(std::shared_ptr<AbstractPlayer> , Game *, Xwindow *);
//        AbstractLevel * getLevel();// TODO: fix later
};
#endif
