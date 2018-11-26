#include "abstractDecorator.h"
using namespace std;

AbstractDecorator::AbstractDecorator(AbstractPlayer *component, Game *g) : AbstractPlayer{g}, player{component} {
    if ( player == nullptr) cout<<"oops"<<endl;
    cout<<"succcess"<<endl;
//    player->setCurrentBlock('T');
} 

/*AbstractLevel * AbstractDecorator::getLevel(){
    return player->level.get();
}*/
