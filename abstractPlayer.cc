#include "abstractPlayer.h"
using namespace std;

void AbstractPlayer::notifyGameover() {}
void AbstractPlayer::notifyTurnover() {}
void AbstractPlayer::notifySpecialAction() {}

int AbstractPlayer::getCurrentScore() {
    return 0;
}
int AbstractPlayer::getHighestScore() {
    return 0;
}
vector<vector<Point>>* AbstractPlayer::getGrid() {
    return nullptr;
}
AbstractLevel* AbstractPlayer::getLevel() {
    return nullptr;
}

ostream& operator<<(ostream &out, const AbstractPlayer &p) {
    return out;
}