#include "forceDecorator.h"
#include "abstractDecorator.h"
using namespace std;

ForceDecorator::ForceDecorator(AbstractPlayer *absPlayer, Game *g): AbstractDecorator{absPlayer, g}{
cout << "enter frce decor ctor" << endl;
if (player != nullptr) cout << "player not null" << endl;
  //  player->setCurrentBlock('T');

}
// player's operation
// check if it is possible to level up/down
void ForceDecorator::setLevel(int level) {
    player->setLevel(level);
}
// add the points of blocks to grid, update the block in drop(), 
void ForceDecorator::drop() {
    player->drop();
}

void ForceDecorator::rotate(bool counter, int step){
    player->rotate(counter, step);
}

void ForceDecorator::setRandom(){
    
}

void ForceDecorator::setCurrentBlock(char type){
    cout<<"force decor"<<endl;
    if (player == nullptr) cout <<"hey player is null now"<<endl;
     player->setCurrentBlock(type);
     cout << "after calling the player setCurBlock" << endl;
  //  AbstractBlock * abs = player->level->generateBlock(ch);

}
bool ForceDecorator::move(string type, int step){
    return player->move(type, step);
}
