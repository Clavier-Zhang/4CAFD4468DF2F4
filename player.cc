#include "player.h"
#include "abstractPlayer.h"
#include "game.h"
#include "blockI.h"
#include <memory>
#include <iostream>
#include "window.h"
using namespace std;

// initialzie the player, draw in the constructor, save window pointer
Player::Player(Game *game, int no, Xwindow *w) : AbstractPlayer{game, no, w} {}

string Player::getGridRow(int row) {
string s;
    for (int i = 0; i < colNum; i++) {
        s += grid[row][i].getType();
    }
    return s;
}

string Player::getGridPoint(int row, int col) {
 return grid[row][col].getType();
}

shared_ptr<AbstractPlayer> Player::getUnderlyingPlayer() { // there is no underlying player
 return nullptr;
}
// assign the point pointer to currentBlock, can
// be used in moveLeft, moveRight
// target::block
/*void Player::setCurrentBlock(char type) {
    // if is lowercase make uppercase
    if ((97 <= type)&&(type <= 122)) { // is lowercase
     int offset = 97-65;
     type = type - offset;
     }
    unique_ptr<AbstractBlock>tmp{level->generateBlock(type)};
    currentBlock->removeAllPoint();
    currentBlock = std::move(tmp);
    currentBlock->initialize(this);
}*/

void Player::nullifyUnderlyingPlayer() {
} // there is no underlying player to set to null

int Player::move(string type, int step) {
bool succeeded = moveHelper(type, step);
 int newStep = step;
 // if unable to move step times, move max allowed times strictly less than step and return how
 // many moves were able to be made
 while (!succeeded) { // && (newStep - i >= 0)) {
  newStep -= 1;
  succeeded = moveHelper(type, newStep);
  }
  return newStep;
}

bool Player::moveHelper(std::string type, int step) {
if (step == 0) return true; // no movement required
    // interpret command
    int deltaX = 0;
    int deltaY = 0;
    if (type == "down") {
        deltaY = step;
    }
    if (type == "left") {
        deltaX = -step;
    }
    if (type == "right") {
        deltaX = step;
    }
    // check if it's movable
    vector<pair<int, int>> coordinates;
    for (Point *p : currentBlock->getPoints()) {
        pair<int, int> c = make_pair(p->getX() + deltaX, p->getY() + deltaY);
        if (isValid(c)) {
            coordinates.emplace_back(c);
        } else {
            return false;
        }
    }
    // clear block first, then add points
    currentBlock->removeAllPoint();
    currentBlock->addPoints(coordinates, this);
    return true;
}

pair<int, int> getLowerLeft(vector<pair<int, int>> &coordinates) {
 int minX = coordinates[0].first;
 int maxY = coordinates[0].second;
 for (int i = 0; i < (int)coordinates.size(); ++i) {
  if (coordinates[i].first < minX) minX = coordinates[i].first;
  if (coordinates[i].second > maxY) maxY = coordinates[i].second;
  }
 pair<int, int> lowerLeft = make_pair(minX, maxY);
 return lowerLeft;
}

int Player::rotate(bool counter, int step) {
bool succeeded = rotateHelper(counter, step);
 int newStep = step;
 // if unable to move step times, move max allowed times strictly less than step and return how
 // many moves were able to be made
 while (!succeeded) { // && (newStep - i >= 0)) {
  newStep -= 1;
  succeeded = rotateHelper(counter, newStep);
  }
  return newStep;
}

bool Player::rotateHelper(bool counter, int step) {
    // if it's a multiple of 4 it ends up in the same place
    if (step % 4 == 0) return true; // end position will be same as start position

    // rotation matrix
    vector<vector<int>> clockWise{{0,-1},{1,0}};
    vector<vector<int>> counterClockWise{{0,1},{-1,0}};
    vector<vector<int>>& current = clockWise;
    if (counter) {
        current = counterClockWise;
    }
    int numRotations = step % 4; // since 4 possible orientations
    vector<pair<int, int>> coordinates; // create cordinates array foro case rot is 0
    for (Point *p : currentBlock->getPoints()) {
     int x = p->getX();
     int y = p->getY();
     pair<int, int> pair = make_pair(x, y);
     coordinates.emplace_back(pair);
     }

   pair<int, int> lowerLeft;
    
    for (int i = 0; i < numRotations; ++i) {
    lowerLeft = getLowerLeft(coordinates);
    vector<pair<int, int>> coorCopy;
    for (pair<int, int> p : coordinates) {
        int x = p.first;
        int y = p.second;
        int newX = x * current[0][0] + y * current[0][1];
        int newY = x * current[1][0] + y * current[1][1];
        pair<int, int> p1 = make_pair(newX, newY);
        coorCopy.emplace_back(p1);
        }

      pair<int, int> rotatedll = getLowerLeft(coorCopy);
      int deltaX = rotatedll.first - lowerLeft.first;
      int deltaY = rotatedll.second - lowerLeft.second;
      coordinates.clear();
      for (pair<int, int> p : coorCopy) {
        pair<int, int> finalPair = make_pair(p.first - deltaX, p.second - deltaY);
      
        if (isValid(finalPair)) {
            coordinates.emplace_back(finalPair);
        } else {
            return false;
        }
       }
     }
    // clear block first, then add points
    currentBlock->removeAllPoint();
    currentBlock->addPoints(coordinates, this);
    return true;
}

// add the points of blocks to grid, update the block in drop(), 
void Player::drop(){
    while (move("down", 1)) {}
        currentBlock->setID(AbstractBlock::getCurId());
        inactiveBlocks[AbstractBlock::getCurId()] = std::move(currentBlock);
        AbstractBlock::incrementCurId();
        currentBlock = std::move(nextBlock);
        currentBlock->initialize(this);
        unique_ptr<AbstractBlock>tmp{level->generateBlock()};
        nextBlock = std::move(tmp);
        recalculateGrid();
        // some logic for determining correct notify will need to go here
        notifyTurnover(); // how do you know not special action?
//      notifySpecialAction();
}

// assign the point pointer to currentBlock, can
// be used in moveLeft, moveRight
// target::block
void Player::setCurrentBlock(char type) {
    unique_ptr<AbstractBlock>tmp{level->generateBlock(type)};
    currentBlock->removeAllPoint();
    currentBlock = std::move(tmp);
    currentBlock->initialize(this);
}

