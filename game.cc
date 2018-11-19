#include "game.h"
#include "player.h"
using namespace std;

// initialize two players
// more constructor for differnnt mode in command line
Game::Game() :
    playerOne{new Player(this)}, 
    playerTwo{new Player(this)}, 
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
ostream& operator<<(ostream &out, const Game &g) {
    return out;
}