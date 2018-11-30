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
Game::Game() :
    playerOne{new Player(this)}, 
    playerTwo{new Player(this)}, 
    currentPlayer{playerOne} {
    // else set to nullptr, important
    this->w.reset(new Xwindow(this->width, this->height)); 
}


Game::~Game() {
 takeOffDecorations();
}

void Game::restart() {
// need to implement
}

// player's operation
// do not need to check, call currentPlayer's method directly
void Game::setLevel(int level) {
    if (this->MIN_LEVEL <= level && level <= this->MAX_LEVEL) {
        currentPlayer->setLevel(level);
        print();
    }
}

void Game::levelUp(int step) {
    int targetLevel = currentPlayer->getLevel() + step;
    if (this->MIN_LEVEL <= targetLevel && targetLevel <= this->MAX_LEVEL) {
        currentPlayer->setLevel(targetLevel);
        print();
    }
}

void Game::levelDown(int step) {
    int targetLevel = currentPlayer->getLevel() - step;
    if (this->MIN_LEVEL <= targetLevel && targetLevel <= this->MAX_LEVEL) {
        currentPlayer->setLevel(targetLevel);
        print();
    }
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
    for (int i = 0; i < step; i++) {
        currentPlayer->drop();
    }
    print();
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
 if (currentPlayer == playerOne) {
    currentPlayer = playerTwo;
 } else {
    currentPlayer = playerOne;
 }
/*
 if (currentPlayer->getLevel() == 0) {// should be 3 or 4, just for testing
        enableSpecialAction("heavy");
        // call to enbleSpecialAction sets needSpecial to false
        needSpecial = true;
        enableSpecialAction("heavy");
        needSpecial = true;
     }*/
}

// finish later
void Game::specialAction() {
  needSpecial = true; 
  turnOver();// switch players
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
    this->drawBigString(10, 5, "23");
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
    return new HeavyDecorator(absPlayer, this);
    }  else if (specialAction == "blind") {
    return new BlindDecorator(absPlayer, this);
    }
    return nullptr; // maybe throw an exception instead later
}

void Game::drawBigString(int x, int y, string s) {
    if (this->currentPlayer == this->playerTwo) {
        x += 18;
    }
    int unit = this->width / 29;
    int realX = x * unit;
    int realY = y * unit;
    if (this->w.get() != nullptr) {
        w->drawString(realX, realY, s, Xwindow::Black);
    }
}

void Game::drawPoint(int x, int y, int w, int h, int c) {
    if (this->w.get() != nullptr) {
        if (this->currentPlayer == this->playerTwo) {
            x += 18;
        }
        int unit = this->width / 29;
        int realX = x * unit;
        int realY = y * unit;
        int realW = w * unit;
        int realH = h * unit;
        this->w->fillRectangle(realX, realY, realW, realH, c);
    }
}