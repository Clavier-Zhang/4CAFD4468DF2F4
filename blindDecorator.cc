#include "blindDecorator.h"
#include "abstractDecorator.h"
using namespace std;

BlindDecorator::BlindDecorator(shared_ptr<AbstractPlayer> absPlayer, Game *g) : AbstractDecorator{absPlayer, g} {}
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

shared_ptr<AbstractPlayer> BlindDecorator::getUnderlyingPlayer() {
return player;
 }
void BlindDecorator::nullifyUnderlyingPlayer() {
 player = nullptr;
 }
void BlindDecorator::rotate(bool counter, int step){
    player->rotate(counter, step);
}

void BlindDecorator::setRandom(){
    
}


string BlindDecorator::getGridRow(int row){
// 3<=row<=9, 3<=col <=12
// cout << "bilnd get grid roow" << endl;
    if (!(( 3 + 3 <=row) && (row <= 12 + 3))) return player->getGridRow(row);
    string s;
    for (int i = 0; i < colNum; i++) {
        if ( 3 <=i && i<=9){
            s+="?";
        }
        else{
            s += player->grid[row][i].getType(); // reconsider this
        }
    }
    return s;


}

void BlindDecorator::setCurrentBlock(char type){
}

bool BlindDecorator::move(string type, int step){
    cout << "blind decor move" << endl;
    return player->move(type, step);
}
