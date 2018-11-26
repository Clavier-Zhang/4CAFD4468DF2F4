#include "game.h"
#include "player.h"
#include "abstractDecorator.h"
#include "blindDecorator.h"
#include <iostream>
#include <iomanip>
using namespace std;

// initialize two players
// more constructor for differnnt mode in command line
Game::Game() :
    playerOne{new Player(this)}, 
    playerTwo{new Player(this)}, 
    currentPlayer{playerOne.get()} {}

void Game::restart() {
// need to implement
}

// player's operation
// do not need to check, call currentPlayer's method directly
void Game::setLevel(int level) {
    currentPlayer->setLevel(level);
    print();
}

void Game::move(string type, int step) {
    currentPlayer->move(type, step);
    print();
}

void Game::rotate(bool counter, int step) {
    currentPlayer->rotate(counter, step);
    print();
}

// later, clear row
void Game::drop() {
    currentPlayer->drop();
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
    if (currentPlayer == playerOne.get()) {
        currentPlayer = playerTwo.get();
    } else {
        currentPlayer = playerOne.get();
    }
}

// finish later
void Game::specialAction() {
  needSpecial = true; 
  turnOver();// switch players
 }


AbstractPlayer *Game::createDecoratedPlayer(string specialAction, AbstractPlayer *ap) {
    if (specialAction == "heavy") {
    return nullptr; // TODO
    }  else if (specialAction == "blind") {
    return nullptr; // TODO
    }
    return nullptr;
}

void Game::enableSpecialAction(string spa, char block) {// information is gathered after the turn is switched to the oppoenent so we decorate currentPlayer
  shared_ptr<AbstractPlayer>keepTrack2=playerTwo;
  shared_ptr<AbstractPlayer>keepTrack1=playerOne;
  //shared_ptr<AbstractPlayer>tmp1{new BlindDecorator (playerOne.get(), this)};
//  shared_ptr<AbstractPlayer>tmp2{new BlindDecorator (playerTwo.get(), this)};
  int num=0;
 if (currentPlayer == playerOne.get()) {
 // shared_ptr<AbstractPlayer>tmp{createDecoratedPlayer(spa, playerOne.get())};
  //new ForceDecorator(playerTwo.get(), this, block)};
  shared_ptr<AbstractPlayer>tmp{new BlindDecorator (playerOne.get(), this)};
  playerOne = tmp;
  currentPlayer = tmp.get(); // ????????????//
  num = 1;
 } else { 
//  shared_ptr<AbstractPlayer>tmp{createDecoratedPlayer(spa, playerTwo.get())};
 // new ForceDecorator(playerOne.get(), this, block)}; 
 // AbstractPlayer *thing = createDecoratedPlayer("force", playerTwo.get());
  shared_ptr<AbstractPlayer>tmp{new BlindDecorator (playerTwo.get(), this)};
 // playerTwo = tmp;
 playerTwo=tmp;
 // currentPlayer = playerTwo.get(); // ??????????????????????????
 currentPlayer = tmp.get();
 num = 2;
 }
  if ( nullptr == playerTwo.get())
    cout <<"the value now is not ok"<< endl;
  needSpecial = false;
  if ( spa=="force"){
  cout<<"before setCurrentBlock"<<endl;
    currentPlayer->setCurrentBlock(block);
  }else if( spa=="blind"){
  
  this->print();
  if(num ==2){

  playerTwo=keepTrack2;
 // currentPlayer = playerTwo.get();
  }
  else
  playerOne=keepTrack1;
//  currentPlayer= playerOne.get();
 
  }
}


// finish later
void Game::print() {
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
