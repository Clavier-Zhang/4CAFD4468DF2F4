#include "game.h"
#include "player.h"
#include "abstractDecorator.h"
#include "blindDecorator.h"
#include "heavyDecorator.h"
#include <iostream>
#include <iomanip>
#include "window.h"
using namespace std;

// initialize two players
// more constructor for differnnt mode in command line
Game::Game(bool isGraphical, int startLvl, string scpt1, string scpt2):
isGraphical{isGraphical} {
    // else set to nullptr, important
    if (isGraphical) {
        this->w.reset(new Xwindow(this->width, this->height));
    } else {
        this->w.reset(nullptr);
    }
    this->playerOne.reset(new Player(this, 1, this->w.get(), startLvl, scpt1));
    this->playerTwo.reset(new Player(this, 2, this->w.get(), startLvl, scpt2));
    this->currentPlayer = this->playerOne;
}


Game::~Game() {
 takeOffDecorations();
}

void Game::restart() {
 int highScoreP1 = playerOne->getHighestScore();
 int highScoreP2 = playerTwo->getHighestScore();
 int lvl1 = playerOne->getLevel();
 int lvl2 = playerTwo->getLevel();
 string scpt1 = playerOne->getInitScpt();
 string scpt2 = playerTwo->getInitScpt();
 
 this->w->fillRectangle(0, 0, this->width, this->height, 0);
 currentPlayer.reset();
 playerOne.reset(new Player(this, 1, this->w.get(), lvl1, scpt1));
 playerTwo.reset(new Player(this, 2, this->w.get(), lvl2, scpt2));
 playerOne->setHighScore(highScoreP1);
 playerTwo->setHighScore(highScoreP2);
 currentPlayer = playerOne;
 print();
}

// player's operation
// do not need to check, call currentPlayer's method directly
void Game::setLevel(int level) {
    if (this->MIN_LEVEL <= level && level <= this->MAX_LEVEL) {
        currentPlayer->setLevel(level);
        print();
    }
}

void Game::addLevelDecorator(int level) {
if (!((level == 3)||(level == 4))) return;
 // otherwise make the level heavy
if (currentPlayer->getUnderlyingPlayer() != nullptr) { // the player is decorated already
   // get a pointer too the the Player and the thing before it
   cout << "clause 1" << endl;
   shared_ptr<AbstractPlayer> cur = currentPlayer;
   shared_ptr<AbstractPlayer> next = cur->getUnderlyingPlayer();
   while (next->getUnderlyingPlayer() != nullptr) {
    cur = next;
    next = next->getUnderlyingPlayer();
    }
   // make a shared ptr that takes the base player (next)
   AbstractPlayer *heavyPlayer = createDecoratedPlayer("heavy", next);
   shared_ptr<AbstractPlayer> heavyLevel {heavyPlayer};
   cur->setUnderlyingPlayer(heavyLevel);
   } else { // just create one decoratori
   cout << "clause 2" << endl;
   enableSpecialAction("heavy");
   }
}

void Game::levelUp(int step) {
    int targetLevel = currentPlayer->getLevel() + step;
    if (this->MIN_LEVEL <= targetLevel && targetLevel <= this->MAX_LEVEL) {
        currentPlayer->setLevel(targetLevel);
//        cout << "inside levelUp" << endl;
      if (!((targetLevel == 4)&&(step == 1))) addLevelDecorator(targetLevel);
        print();
    }
}

void Game::removeLevelDecorator(int level) {
 if ((level == 3)||(level == 4)) return;
 if (currentPlayer->getUnderlyingPlayer() == nullptr) return;
 if (currentPlayer->getUnderlyingPlayer()->getUnderlyingPlayer() != nullptr) {// there is a decoration in adition to level
   shared_ptr<AbstractPlayer> cur = currentPlayer;
   shared_ptr<AbstractPlayer> next = cur->getUnderlyingPlayer();
   shared_ptr<AbstractPlayer> bottom = next->getUnderlyingPlayer();
   while (bottom->getUnderlyingPlayer() != nullptr) {
    cur = next;
    next = bottom;
    bottom = bottom->getUnderlyingPlayer();
    }
   cur->setUnderlyingPlayer(bottom);
 } else {
   if (currentPlayer->getNo() == 1) {
   shared_ptr<AbstractPlayer> cpy = playerOne->getUnderlyingPlayer();
   playerOne->nullifyUnderlyingPlayer();
   currentPlayer->nullifyUnderlyingPlayer();
   playerOne->setUnderlyingPlayer(cpy);
   currentPlayer = playerOne;
   } else {
   shared_ptr<AbstractPlayer> cpy = playerTwo->getUnderlyingPlayer();
   playerTwo->nullifyUnderlyingPlayer();
   currentPlayer->nullifyUnderlyingPlayer();
   playerTwo->setUnderlyingPlayer(cpy);
   currentPlayer = playerTwo;
  }
 }
}
/*
            playerOne->nullifyUnderlyingPlayer();
            currentPlayer->nullifyUnderlyingPlayer();
            playerOne.reset();
            currentPlayer.reset();
            playerOne = tmp;
            currentPlayer = playerOne;
*/
void Game::levelDown(int step) {
    int targetLevel = currentPlayer->getLevel() - step;
    if (this->MIN_LEVEL <= targetLevel && targetLevel <= this->MAX_LEVEL) {
        currentPlayer->setLevel(targetLevel);
        if (!((targetLevel == 3)&&(step == 1))) removeLevelDecorator(targetLevel); 
        print();
    }
}

void Game::setRandom(bool rand, string file){
    currentPlayer->setRandom(rand, file);
}

int Game::getLevel(){
    return currentPlayer->getLevel();
}

void Game::move(string type, int step) {
 currentPlayer->move(type, step);
 print();
}

void Game::rotate(bool counter, int step) {
    currentPlayer->rotate(counter, step);
    print();
}

void Game::drop(int step) {
    currentPlayer->drop();
    print();
}

int Game::getNumDrop(){
    return currentPlayer->getNumDrop();
}

void Game::setNumDrop(int n){
    currentPlayer->setNumDrop(n);
}

bool Game::gameOver() {
 return isOver;
}

bool Game::isNeedSpecial() {
 return needSpecial;
 }

void Game::setGameOver() {
 isOver = true;
}

// next player's turn
void Game::turnOver() {
    takeOffDecorations();
    if (currentPlayer.get() == playerOne.get()) {
        currentPlayer = playerTwo;
    } else {
        currentPlayer = playerOne;
    }
  int curPlayerLevel = currentPlayer->getLevel();
  if ((curPlayerLevel == 3)||(curPlayerLevel == 4)) enableSpecialAction("heavy");
}

// finish later
void Game::specialAction() {
  turnOver();// switch players
  needSpecial = true;
 }

void Game::enableSpecialAction(string spa) {// information is gathered after the turn is switched to the oppoenent so we decorate currentPlayer
 if (currentPlayer == playerOne) {
    AbstractPlayer *decoratedPlayer = createDecoratedPlayer(spa, playerOne);
    shared_ptr<AbstractPlayer>tmp{decoratedPlayer};
    playerOne = tmp;
    currentPlayer = playerOne;
 } else { // currentPlayer is player2
    AbstractPlayer *decoratedPlayer = createDecoratedPlayer(spa, playerTwo);
    shared_ptr<AbstractPlayer>tmp{decoratedPlayer};
    playerTwo = tmp;
    currentPlayer = playerTwo;
 }
  needSpecial = false;
}

void Game::force(char c) { 
 currentPlayer->setCurrentBlock(c);
 needSpecial = false;
}

// finish later
void Game::print() {
    // this->drawBigString(2,2,"-",1);
    // print level
    cout << "Level:";
    cout << setw(5) << playerOne->getLevel();
    cout  << setw(7) << " ";
    cout << "Level:";
    cout << setw(5) << playerTwo->getLevel();
    cout << endl;
    // print score
    cout << "Score:";
    cout << setw(5) << playerOne->getCurrentScore();
    cout  << setw(7) << " ";
    cout << "Score:";
    cout << setw(5) << playerTwo->getCurrentScore();
    cout << endl;
    // print highest score
    cout << "Highest:";
    cout << setw(3) << playerOne->getHighestScore();
    cout  << setw(7) << " ";
    cout << "Highest:";
    cout << setw(3) << playerTwo->getHighestScore();
    cout << endl;
    // print dash
    cout << "-----------";
    cout << setw(7) << " ";
    cout << "-----------";
    cout << endl;
    // print grid
    for (int i = 0; i < 18; i++) {
        cout << playerOne->getGridRow(i);
        cout << setw(7) << " ";
        cout << playerTwo->getGridRow(i);
        cout << endl;
    }
    // print dash
    cout << "-----------";
    cout  << setw(7) << " ";
    cout << "-----------";
    cout << endl;
    // print next
    cout << "Next:";
    cout << setw(6) << " ";
    cout << setw(7) << " ";
    cout << "Next:";
    cout << setw(6) << " " << endl;
    cout << this->getNextBlockFirstRow(playerOne->getNextBlock());
    cout << setw(7) << " ";
    cout << this->getNextBlockFirstRow(playerTwo->getNextBlock());
    cout << endl;
    cout << this->getNextBlockSecondRow(playerOne->getNextBlock());
    cout << setw(7) << " ";
    cout << this->getNextBlockSecondRow(playerTwo->getNextBlock());
    cout << endl;
}

// helper, modify later
string Game::getNextBlockFirstRow(string type) {
    if (type == "I") {
        return "           ";
    } else if (type == "J") {
        return "J          ";
    } else if (type == "L") {
        return "  L        ";
    } else if (type == "O") {
        return "OO         ";
    } else if (type == "S") {
        return " SS        ";
    } else if (type == "Z") {
        return "ZZ         ";
    }
    return "TTT        ";
}

string Game::getNextBlockSecondRow(string type) {
    if (type == "I") {
        return "IIII       ";
    } else if (type == "J") {
        return "JJJ        ";
    } else if (type == "L") {
        return "LLL        ";
    } else if (type == "O") {
        return "OO         ";
    } else if (type == "S") {
        return "SS         ";
    } else if (type == "Z") {
        return " ZZ        ";
    }
    return " T         ";
}

Xwindow * Game::getWindow() {
    return this->w.get();
}

// Private helper functions
void Game::takeOffDecorations() {
    shared_ptr<AbstractPlayer> tmp = currentPlayer->getUnderlyingPlayer();// get the undecorated player component
    while (tmp != nullptr) { // the player still has decorations
    // schema for removing decoration:
    // 1. set the currentPlayer and playerX pointers to the undecorated player component to null (tmp is a copy of this)
    // 2. call on both currentPlayer and playerX; this deletes only the decorator
    // 3. reassign the undecorated player component to playerX and currentPlayer
        if (currentPlayer == playerOne) {
            playerOne->nullifyUnderlyingPlayer();
            currentPlayer->nullifyUnderlyingPlayer();
            playerOne.reset();
            currentPlayer.reset();
            playerOne = tmp;
            currentPlayer = playerOne;
        } else { // currentPlayer is playerTwo
            playerTwo->nullifyUnderlyingPlayer();
            currentPlayer->nullifyUnderlyingPlayer();
            playerTwo.reset();
            currentPlayer.reset();
            playerTwo = tmp;
            currentPlayer = playerTwo;
        }
        tmp = currentPlayer->getUnderlyingPlayer();
    }
}

AbstractPlayer *Game::createDecoratedPlayer(string specialAction, shared_ptr<AbstractPlayer> absPlayer) {
    if (specialAction == "heavy") {
   // shared_ptr firstHeavy = make_shared(new HeavyDecorator(absPlayer, this, w.get()));
    return new HeavyDecorator(absPlayer, this, w.get());// since 2 heavy for special action
    }  else if (specialAction == "blind") {
    cout<<"calling blind decor"<<endl;
    return new BlindDecorator(absPlayer, this, w.get());
    }
    return nullptr; // maybe throw an exception instead later
}

void Game::drawBigString(int x, int y, string s, int playerNum) {
    if (this->w.get() != nullptr) {
        x = x + (playerNum - 1) * 18;
        int unit = 18;
        int realX = x * unit;
        int realY = y * unit;
        w->drawString(realX, realY, s, Xwindow::Black);
    }
}

void Game::undrawBigString(int x, int y, string s, int playerNum) {
    if (this->w.get() != nullptr) {
        x = x + (playerNum - 1) * 18;
        int unit = 18;
        int realX = x * unit;
        int realY = y * unit;
        w->drawString(realX, realY, s, 0);
    }
}

void Game::drawPoint(int x, int y, int w, int h, int c, int playerNum) {
    if (this->w.get() != nullptr) {
        x = x + (playerNum - 1) * 18;
        int unit = 18;
        int realX = x * unit;
        int realY = y * unit + 5;
        int realW = w * unit;
        int realH = h * unit;
        this->w->fillRectangle(realX, realY, realW, realH, c);
    }
}

void Game::undrawPoint(int x, int y, int w, int h, int playerNum) {
   if (this->w.get() != nullptr) {
        x = x + (playerNum - 1) * 18;
        int unit = 18;
        int realX = (x + (playerNum - 1) * 18) * unit;
        int realY = y * unit;
        int realW = w * unit;
        int realH = h * unit;
        this->w->fillRectangle(realX, realY, realW, realH, 0);
    }
}
