#include "abstractPlayer.h"
#include "game.h"
#include "abstractLevel.h"
#include "point.h"
#include <string.h>
#include <memory>
#include <map>
#include <iostream>
#include "window.h"
using namespace std;

// constructor
AbstractPlayer::AbstractPlayer(Game *game, int no, Xwindow *w, string scpt):
    no{no}, initScpt{scpt},level{nullptr},currentBlock{nullptr},nextBlock{nullptr}{
        // initialize the grid
        for (int i = 0; i < rowNum; i++) {
            vector<Point> row;
            for (int j = 0; j < colNum; j++) {
                string empty = " ";
                row.emplace_back(Point(j,i,empty, this->no, w));
            }
            grid.emplace_back(row);
        }

        //initliaze blocks and level


        //currentBlock->initialize(this);
        this->game = game;

        // initialize the graphical
        for (int x = 0; x < this->colNum; x++) {
            game->drawPoint(x, 2, 1, 1, 11, this->no);
        }
        game->drawBigString(1, 1, "Level:", this->no);
        game->drawBigString(1, 2, "Score:", this->no);
        game->drawBigString(9, 2, "0", this->no);
        game->drawBigString(9, 1, "0", this->no);
        for (int x = 0; x < this->colNum; x++) {
            game->drawPoint(x, 21, 1, 1, 11, this->no);
        }
        game->drawBigString(0, 24, " Next:", this->no);
        game->drawBigString(4, 24, "High Score:", this->no);
        game->drawBigString(10, 24, "0", this->no);
    }

// important
/*AbstractPlayer::AbstractPlayer(Game *game):,currentBlock{level->generateBlock()},
  nextBlock{level->generateBlock()} {
// initialize the grid
for (int i = 0; i < rowNum; i++) {
vector<Point> row;
for (int j = 0; j < colNum; j++) {
string empty = " ";
row.emplace_back(Point(j,i,empty, this->no, nullptr));
}
grid.emplace_back(row);
}
currentBlock->initialize(this);
this->game = game;
}*/

AbstractPlayer::~AbstractPlayer(){
}

Game *AbstractPlayer::getGame() { return game;}

// check if possible to level up or down
void AbstractPlayer::setLevel(int level){
    if(this->level != nullptr) this->undrawLevel();
    if (level == 0) {
        this->level.reset(new LevelZero{initScpt});
    } else if (level == 1) {
        this->level.reset(new LevelOne);
    }else if (level == 2){
        this->level.reset(new LevelTwo);
    }else if (level == 3){
        this->level.reset(new LevelThree);
    }else if ( level == 4){
        this->level.reset(new LevelFour);
    }
    this->drawLevel();
}


bool AbstractPlayer::isValid(pair<int, int> &c) {
    if (c.first < 0 || c.second < 0) {
        return false;
    }
    if (c.first >= colNum || c.second >= rowNum) {
        return false;
    }
    Point *p = this->getPoint(c);
    if (p->getType() != " " && !currentBlock->contain(p)) {
        return false;
    }
    return true;
}

void AbstractPlayer::recalculateGrid() {
    bool shouldClear;
    int offset = 0;
    for (int row = rowNum - 1; row > reservedRowNum; row--) {
        shouldClear = false;
        for (int col = 0; col < colNum; col++) {
            if ((grid[row][col].getType() != " ") && (col == colNum - 1)) shouldClear = true;
            if (grid[row][col].getType() == " ") break; 
        }

        if(shouldClear) {
            clearRow(row);
            offset++;
        } else {
            shiftRowDown(row, offset);
        }
    }
    if (offset>=1){
        cout<<"undrawscore"<<endl;
        this->undrawScore();
        cout<<"finished undrawscore"<<endl;
        currentScore+=((getLevel()+offset)*(getLevel()+offset));
        if(offset>=2)notifySpecialAction();
        else notifyTurnover();
    }
    else notifyTurnover();
    // the turns were switched
    applyLevelEffects(offset);
    recalculateInactiveBlocks();
    updateScore();
}

void AbstractPlayer::updateScore(){

    if (this->currentScore > this->highestScore) {
        this->highestScore = this->currentScore;
    }
    this->drawScore();

}

void AbstractPlayer::clearRow(int row) {
    for (int col = 0; col < colNum; col++){
        Point *p = &this->grid[row][col];
        p->setType(" ");
        for (auto cell : inactiveBlocks[p->getID()]->getPoints()){
            if (cell == p){
                inactiveBlocks[p->getID()].get()->removeOnePoint(p);
            }
        }
        p->setID(-1);// reset to default
    }
}

void AbstractPlayer::shiftRowDown(int row, int offset) {
    if (row < reservedRowNum || offset == 0) return; //checks if were within correct range
    for (int col =0; col < colNum; col++) { // iterates through the columns in the current row
        Point *p = &grid[row][col];// gets the point to be moved
        if (p->getType() != " ") {
            Point *newP = &grid[row+offset][col]; // finds the place the point needs to be moved
            newP->setID(p->getID());// changes id

            for (auto cell : inactiveBlocks[p->getID()]->getPoints()) {
                if (cell == p) {//once we find the point in the block...
                    pair<int, int> coor = make_pair(newP->getX(), newP->getY());
                    inactiveBlocks[p->getID()].get()->addPoint(coor, this); // creates the point that it should be moved to
                    grid[row][col].setType(" ");
                    inactiveBlocks[p->getID()].get()->removeOnePoint(p);// removes the current point from the block
                }

            }
            p->setID(-1);
        }
    }
}

void AbstractPlayer::recalculateInactiveBlocks(){
    auto it= inactiveBlocks.begin();
    while(it != inactiveBlocks.end()){
        if (it->second->getPoints().size() == 0){
            currentScore+=it->second->getScore();
            auto toErase = it;
            cout<<it->first<<endl;
            it++;
            it=inactiveBlocks.erase(toErase);
        }else{
            it++;
        }
    }
    /*for(auto & entry : inactiveBlocks){
        if (entry.second!=nullptr && entry.second->getPoints().size() == 0){
            currentScore += entry.second->getScore();
//            entry.second.reset(nullptr);

            inactiveBlocks.erase(entry.first);
        }
    }*/
}

void AbstractPlayer::applyLevelEffects(int offset){
    if (level->getLevel() == 4){
        shared_ptr<LevelFour> lf = static_pointer_cast<LevelFour>(level);
        offset>0?lf->resetNumUncleared():lf->incNumUncleared();
        int uncleared= lf->getNumUncleared();

        if (uncleared > 0 && uncleared % 5 == 0) {
            unique_ptr<AbstractBlock> divider {lf->createCustomBlock('X')};
            divider->initialize(this);
            divider->setID(AbstractBlock::getCurId());
            inactiveBlocks[AbstractBlock::getCurId()] = std::move(divider);
            AbstractBlock::incrementCurId();
        }
    }
}

void AbstractPlayer::setHighScore(int hi) {
    highestScore = hi;
}

void AbstractPlayer::setRandom(bool rand, string file) {
    level->setRandom(rand, file);
}

// observer pattern
void AbstractPlayer::notifyGameover() {
    game->setGameOver();
}

void AbstractPlayer::notifyTurnover() {
    game->turnOver();
}

void AbstractPlayer::notifySpecialAction() {
    game->specialAction();
}

// getter
int AbstractPlayer::getCurrentScore() {
    return currentScore;
}

int AbstractPlayer::getHighestScore() {
    return highestScore;
}

int AbstractPlayer::getLevel() {
    return level->getLevel();
}

int AbstractPlayer::getNo(){
    return no;
}

string AbstractPlayer::getInitScpt(){
    return initScpt;
}

int AbstractPlayer::getNumDrop(){
    return numDrop;
}

void AbstractPlayer::setNumDrop(int n){
    numDrop = n;
}

string AbstractPlayer::getNextBlock() {
    return nextBlock->getType();
}

string AbstractPlayer::getCurrentBlock() {
    return currentBlock->getType();
}
//USED IN DECORATOR TO MAKE NEXT BLOCK NON NULL
void AbstractPlayer::setNextBlock(string type){
    unique_ptr<AbstractBlock>tmp{level->generateBlock(type[0])};
    nextBlock = std::move(tmp);
    this->drawNextBlock();
}

void AbstractPlayer::setCurrentBlock(string type){
    unique_ptr<AbstractBlock>tmp{level->generateBlock(type[0])};
    currentBlock = std::move(tmp);
    currentBlock->initialize(this);
}

Point* AbstractPlayer::getPoint(pair<int, int> &c) {
    return &grid[c.second][c.first];
}

void AbstractPlayer::drawScore(){
    if (game->getWindow() != nullptr) {
        game->drawBigString(10, 24, std::to_string(this->highestScore), this->no);
        game->drawBigString(9, 2, std::to_string(this->currentScore), this->no);
    }
}

void AbstractPlayer::undrawScore(){
    if (game->getWindow() != nullptr) {
        game->undrawBigString(10, 24, std::to_string(this->highestScore), this->no);
        game->undrawBigString(9, 2, std::to_string(this->currentScore), this->no);
    }
}

void AbstractPlayer::drawLevel(){
    if (game->getWindow() != nullptr) {
        game->drawBigString(9, 1, std::to_string(this->level->getLevel()), this->no);
    }
}

void AbstractPlayer::undrawLevel(){
    if (game->getWindow() != nullptr) {
        game->undrawBigString(9, 1, std::to_string(this->level->getLevel()), this->no);
    }
}

void AbstractPlayer::drawNextBlock(){
    if (game->getWindow() != nullptr) {
        for (auto &p : this->nextBlock->getPositions()) {
            int colour = 0;
            string type = this->nextBlock->getType();
            if (type == " ") {
                colour = 0;
            }
            if (type == "I") {
                colour = 2;
            }
            if (type == "J") {
                colour = 3;
            }
            if (type == "L") {
                colour = 4;
            }
            if (type == "O") {
                colour = 5;
            }
            if (type == "S") {
                colour = 6;
            }
            if (type == "T") {
                colour = 7;
            }
            if (type == "X") {
                colour = 0;
            }
            if (type == "Z") {
                colour = 9;
            }
            game->drawPoint(p.first, p.second + this->rowNum + 5, 1, 1, colour, this->no);
        }
    }
}

void AbstractPlayer::undrawNextBlock(){
    if (game->getWindow() != nullptr) {
        for (pair<int, int> &p : this->nextBlock->getPositions()) {
            game->drawPoint(p.first, p.second + this->rowNum + 5, 1, 1, 0, this->no);
        }
    }
}

void AbstractPlayer::setGridType(int row, int col, string c){
    grid[row][col].setType(c);
}
