#include <string>
#include "abstractBlock.h"
using namespace std;

AbstractBlock::AbstractBlock(string type) 
    : type{type} {}

string AbstractBlock::getType() {
    return this->type;
}