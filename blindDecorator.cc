#include "blindDecorator.h"
#include "abstractDecorator.h"
using namespace std;

BlindDecorator::BlindDecorator(AbstractPlayer *absPlayer, Game *g) : AbstractDecorator{absPlayer, g} {}
// player's operation
// check if it is possible to level up/down
// add the points of blocks to grid, update the block in drop(), 
void BlindDecorator::setLevel(int level) {
    player->setLevel(level);
}
// add the points of blocks to grid, update the block in drop(), 
void BlindDecorator::drop() {
    player->drop();
}

void BlindDecorator::rotate(bool counter, int step){
    player->rotate(counter, step);
}

void BlindDecorator::setRandom(){
    
}


string BlindDecorator::getGridRow(int row){
// 3<=row<=9, 3<=col <=12
    if (!(( 3 <=row) && (row <=9))) return player->getGridRow(row);
    string s;
    for (int i = 0; i < colNum; i++) {
        if ( 3 <=i && i<=12){
            s+="?";
        }
        else{
            s += grid[row][i].getType();
        }
    }
    return s;


}

void BlindDecorator::setCurrentBlock(char type){
}

bool BlindDecorator::move(string type, int step){
    return player->move(type, step);
}
