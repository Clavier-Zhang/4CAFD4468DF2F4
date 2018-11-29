#include "player.h"
#include "abstractPlayer.h"
#include "game.h"
#include "blockI.h"
#include <memory>
#include <iostream>
using namespace std;

// initialzie the player, draw in the constructor, save window pointer
Player::Player(Game *game) : AbstractPlayer{game} {}

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
 cout << "Player::getUnderlyingPlayer" << endl;
 return nullptr;
}

void Player::nullifyUnderlyingPlayer() {
 cout << "Player::nullify" << endl;
} // there is no underlying player to set to null

bool Player::move(std::string type, int step) {
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

void Player::rotate(bool counter, int step) {
    // rotation matrix
    if (step % 4 == 0) return;

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

   pair<int, int> lowerLeft;// = getLowerLeft(coordinates);
    
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
            return;
        }
       }
     }
    // clear block first, then add points
    currentBlock->removeAllPoint();
    currentBlock->addPoints(coordinates, this);
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
        notifyTurnover(); // how do you know not special action?
      //  notifySpecialAction();
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
