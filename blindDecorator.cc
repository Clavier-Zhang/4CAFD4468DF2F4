#include "blindDecorator.h"
#include "abstractDecorator.h"
#include "game.h"
using namespace std;

// Useful constants
const int MIN_ROW_BOUND = 3;
const int MAX_ROW_BOUND = 12;
const int MIN_COL_BOUND = 2;
const int MAX_COL_BOUND = 8;

BlindDecorator::BlindDecorator(shared_ptr<AbstractPlayer> absPlayer, Game *g, Xwindow * w) : 
AbstractDecorator{absPlayer, g, w} {
}

BlindDecorator::~BlindDecorator() {
}

// add the points of blocks to grid, update the block in drop(), 
void BlindDecorator::drop(bool shouldClearBlind) {
//player->drop();
//for (int i = MIN_ROW_BOUND + reservedRowNum; i <= MAX_ROW_BOUND + reservedRowNum; ++i) {
 // for (int j = MIN_COL_BOUND; j <= MAX_COL_BOUND; ++j) {
/* cout << "inside the loop" << endl;
 shared_ptr<AbstractPlayer> bPlayer = player;
 cout << "one" << endl;
 Game *ourGame = bPlayer->getGame();
 cout << "two" << endl;
 int pNum = bPlayer->getNo();
 cout << "three" << endl;
 ourGame->undrawPoint(j, i, 1, 1, pNum);
 cout << "four" << endl;*/
// cout << "above undraw" << endl;
//player->undrawGridPoint(j, i);
// cout << "under undraw" << endl;
// getBasePlayer()->getGame()->undrawPoint(j, i, 1, 1, getBasePlayer()->getNo());
//  }
// } 
 player->drop(true);
/*for (int i = MIN_ROW_BOUND + reservedRowNum; i <= MAX_ROW_BOUND + reservedRowNum; ++i) {
  for (int j = MIN_COL_BOUND; j <= MAX_COL_BOUND; ++j) {
        string type = player->getGridPoint(i, j); 
        cout<<"got type"<<endl;
        player->setGridType(i,j,type);
        cout<<"set type" <<endl;
  }

  
}*/
//player->drop();
}

shared_ptr<AbstractPlayer> BlindDecorator::getUnderlyingPlayer() {
 return player;
}

void BlindDecorator::nullifyUnderlyingPlayer() {
 player = nullptr;
}

shared_ptr<AbstractPlayer> BlindDecorator::getBasePlayer() {
 shared_ptr<AbstractPlayer> tmp = getUnderlyingPlayer();
// if (tmp == nullptr) cout << "what the fuck" << endl;
 while (tmp->getUnderlyingPlayer() != nullptr) {
  cout << "in this loop?" << endl;
  tmp = tmp->getUnderlyingPlayer();
  }
  return tmp;
}

int BlindDecorator::rotate(bool counter, int step, bool isBlind){
 return player->rotate(counter, step, true);
}

void BlindDecorator::drawGridPoint(int x, int y, int col) {
 player->drawGridPoint(x, y, col);
 }

void BlindDecorator::undrawGridPoint(int x, int y) {
if (player == nullptr) cout << "wtf" << endl;
if (player.get() == nullptr) cout << "wtf" << endl;
cout << "before player->undraw" << endl;
player->undrawGridPoint(x, y);
cout << "after player->undraw" << endl;
 }

string BlindDecorator::getGridPoint(int row, int col) {
 if (((MIN_ROW_BOUND + reservedRowNum  <= row) && (row <= MAX_ROW_BOUND + reservedRowNum)) && ((MIN_COL_BOUND <= col) && (col <= MAX_COL_BOUND))) {
 //getBasePlayer()->getGame()->drawPoint(col, row, 1, 1, 8, getBasePlayer()->getNo());
 drawGridPoint(col, row, 8); // orange
 return "?";
 }
 return player->getGridPoint(row, col);
}

string BlindDecorator::getGridRow(int row){
 if (!(( MIN_ROW_BOUND + reservedRowNum <= row) && (row <= MAX_ROW_BOUND + reservedRowNum))) return player->getGridRow(row);
 string s;
 for (int i = 0; i < colNum; i++) {
    s += getGridPoint(row, i);
 }
 return s;
}

void BlindDecorator::setCurrentBlock(char c) {
 player->setCurrentBlock(c);
 }

int BlindDecorator::move(string type, int step, bool isBlind){
 return player->move(type, step, true);
}


