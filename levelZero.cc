#include "abstractBlock.h"
#include "levelZero.h"
#include "abstractLevel.h"
#include "blockI.h"
#include "blockJ.h"
#include "blockL.h"
#include "blockO.h"
#include "blockS.h"
#include "blockT.h"
#include "blockZ.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

LevelZero::LevelZero() : AbstractLevel{0, "", false} {
    fstream file{"sequence1.txt"};
    string s;
    string all = "";
    while (file >> s) {
        all += s;
    }
    this->sequence = all;
};

LevelZero::~LevelZero() {}

AbstractBlock* LevelZero::generateBlock() {
    if (this->seqAt == (int)this->sequence.length()) {
        this->seqAt = 0;
    }
    char c = this->sequence[this->seqAt];
    this->seqAt++;
    if (c == 'I') {
        return new BlockI((this->level + 1) * (this->level + 1));
    }
    if (c == 'J') {
        return new BlockJ((this->level + 1) * (this->level + 1));
    }
    if (c == 'L') {
        return new BlockL((this->level + 1) * (this->level + 1));
    }
    if (c == 'O') {
        return new BlockO((this->level + 1) * (this->level + 1));
    }
    if (c == 'S') {
        return new BlockS((this->level + 1) * (this->level + 1));
    }
    if (c == 'T') {
        return new BlockT((this->level + 1) * (this->level + 1));
    }
    if (c == 'Z') {
        return new BlockZ((this->level + 1) * (this->level + 1));
    }
    return new BlockI((this->level + 1) * (this->level + 1));
}
