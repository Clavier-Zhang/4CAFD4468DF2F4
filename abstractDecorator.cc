#include "abstractDecorator.h"
#include "levelZero.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"
using namespace std;

AbstractDecorator::AbstractDecorator(shared_ptr<AbstractPlayer> component, Game *g, 
Xwindow *w) : AbstractPlayer{g,component->getNo(), w, component->getInitScpt()},
player{component} { 
//initializes the level
    int l = component->getLevel();
    if (l == 0) {
        this->level.reset(new LevelZero{initScpt});
    } else if (l == 1) {
        this->level.reset(new LevelOne);
    }else if (l == 2){
        this->level.reset(new LevelTwo);
    }else if (l == 3){
        this->level.reset(new LevelThree);
    }else{
        this->level.reset(new LevelFour);
    }
//initializes the nextBlock
   setNextBlock(component->getNextBlock());
}

