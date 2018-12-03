#include "heavyDecorator.h"
#include "abstractBlock.h"
using namespace std;

HeavyDecorator::HeavyDecorator(shared_ptr<AbstractPlayer> absPlayer, Game *g, Xwindow * w) :
AbstractDecorator{absPlayer, g, w} {}

void HeavyDecorator::drop(bool shouldClearBlind) {
 player->drop(shouldClearBlind);
}

shared_ptr<AbstractPlayer> HeavyDecorator::getUnderlyingPlayer() {
 return player;
}

void HeavyDecorator::nullifyUnderlyingPlayer() {
 player = nullptr;
}

void HeavyDecorator::setUnderlyingPlayer(shared_ptr<AbstractPlayer> play) {
 player = play;
 // UNLESS YOU MADE A COPY SOMETHERE THIS WILL DESTROY IT BEWARE
}

void HeavyDecorator::drawGridPoint(int x, int y, int col) {
 player->drawGridPoint(x, y, col);
 }

void HeavyDecorator::undrawGridPoint(int x, int y) {
player->undrawGridPoint(x, y);
 }

int HeavyDecorator::rotate(bool counter, int step, bool isBlind) {
int newStep = player->rotate(counter, step, isBlind);
getBasePlayer()->move("down", newStep, isBlind);
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

int HeavyDecorator::move(string type, int step, bool isBlind) {
int newStep = player->move(type, step, isBlind);
getBasePlayer()->move("down", newStep, isBlind);
return newStep;// return this r the retval of the preceding line?
}

shared_ptr<AbstractPlayer> HeavyDecorator::getBasePlayer() {
 shared_ptr<AbstractPlayer> tmp = getUnderlyingPlayer();
 while (tmp->getUnderlyingPlayer() != nullptr) {
  tmp = tmp->getUnderlyingPlayer();
  }
  return tmp;
}
