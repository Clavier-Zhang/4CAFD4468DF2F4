#include "abstractLevel.h"
using namespace std;

AbstractLevel::AbstractLevel(int level, std::string sequence, bool isRandom )
    : level{level}, sequence{sequence}, isRandom{isRandom} {}

AbstractLevel::~AbstractLevel() {}

int AbstractLevel::getLevel() {
    return this->level;
}