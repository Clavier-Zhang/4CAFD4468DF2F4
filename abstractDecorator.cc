#include "abstractDecorator.h"
using namespace std;

AbstractDecorator::AbstractDecorator(shared_ptr<AbstractPlayer> component, Game *g, 
Xwindow *w) : 
AbstractPlayer{g,component->getNo(), w, component->getInitScpt()}, player{component} {
} 

/*AbstractLevel * AbstractDecorator::getLevel(){
    return player->level.get();
}*/
