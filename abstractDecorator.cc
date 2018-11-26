#include "abstractDecorator.h"
using namespace std;

AbstractDecorator::AbstractDecorator(shared_ptr<AbstractPlayer> component, Game *g) : AbstractPlayer{g}, player{component} {
} 

/*AbstractLevel * AbstractDecorator::getLevel(){
    return player->level.get();
}*/
