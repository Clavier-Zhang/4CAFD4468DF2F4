#include "game.h"
#include "player.h"
#include <iostream>
#include <iomanip>
using namespace std;

// initialize two players
// more constructor for differnnt mode in command line
Game::Game() :
    playerOne{new Player(this, this->xw.get())}, 
    playerTwo{new Player(this, this->xw.get())}, 
    currentPlayer{playerOne.get()},
    xw{new Xwindow()} {}

// player's operation
// do not need to check, call currentPlayer's method directly
void Game::setLevel(int level) {
    this->currentPlayer->setLevel(level);
}

void Game::moveLeft(int step) {
    this->currentPlayer->moveLeft(step);
}

void Game::moveRight(int step) {
    this->currentPlayer->moveRight(step);
}

void Game::moveDown(int step) {
    this->currentPlayer->moveDown(step);
}

void Game::rotateClockwise() {
    this->currentPlayer->rotateClockwise();
}

void Game::rotateCounterClockwise() {
    this->rotateCounterClockwise();
}

void Game::drop() {
    this->currentPlayer->drop();
}

void Game::gameOver() {
    this->isOver = true;
}

// next player's turn
void Game::turnOver() {
    if (this->currentPlayer == this->playerOne.get()) {
        this->currentPlayer = this->playerTwo.get();
    } else {
        this->currentPlayer = this->playerOne.get();
    }
}

// finish later
void Game::specialAction() {}

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
    cout  << setw(7) << " ";
    cout << "-----------";
    cout << endl;
    // print grid
    for (int i = 0; i < 15; i++) {
        cout << playerOne->getGridRow(i);
        cout  << setw(7) << " ";
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
    cout  << setw(7) << " " << endl;
}