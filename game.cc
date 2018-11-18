#include "game.h"
using namespace std;
// initialize two players
Game::Game() {}
// player's operation
// do not need to check, call currentPlayer's method directly
void Game::setLevel() {}
void Game::moveLeft() {}
void Game::moveRight() {}
void Game::moveDown() {}
void Game::rotateClockwise() {}
void Game::rotateCounterClockwise() {}
void Game::drop() {}
// more command to be determined
void Game::gameOver() {}
void Game::turnOver() {}
void Game::specialAction() {}
ostream& operator<<(ostream &out, const Game &g) {
    
}