#include "heavyDecorator.h"
#include "abstractBlock.h"
using namespace std;

HeavyDecorator::HeavyDecorator(shared_ptr<AbstractPlayer> absPlayer, Game *g, Xwindow * w) :
AbstractDecorator{absPlayer, g, w} {}

void HeavyDecorator::drop() {
 player->drop();
}

shared_ptr<AbstractPlayer> HeavyDecorator::getUnderlyingPlayer() {
 return player; // prbably move up to decorator
}

void HeavyDecorator::nullifyUnderlyingPlayer() {
 player = nullptr;
}

int HeavyDecorator::rotate(bool counter, int step) {
int newStep = player->rotate(counter, step);
getBasePlayer()->move("down", newStep);
return newStep;// return this r the retval of the preceding line?
}

string HeavyDecorator::getGridPoint(int row, int col) {
return player->getGridPoint(row, col);
}

string HeavyDecorator::getGridRow(int row) {
return player->getGridRow(row);
}

void HeavyDecorator::setCurrentBlock(char c) {
 player->setCurrentBlock(c);
 }

int HeavyDecorator::move(string type, int step) {
int newStep = player->move(type, step);
getBasePlayer()->move("down", newStep);
return newStep;// return this r the retval of the preceding line?
}

shared_ptr<AbstractPlayer> HeavyDecorator::getBasePlayer() {
 shared_ptr<AbstractPlayer> tmp = getUnderlyingPlayer();
 while (tmp->getUnderlyingPlayer() != nullptr) {
  tmp = tmp->getUnderlyingPlayer();
  }
  return tmp;
}
