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

AbstractBlock* LevelZero::generateBlock(char type) {
    if (type != ' ') return createCustomBlock(type);
    if (this->seqAt == (int)this->sequence.length()) {
        this->seqAt = 0;
    }
    char c = this->sequence[this->seqAt];
    this->seqAt++;
    return createCustomBlock(c);

}
