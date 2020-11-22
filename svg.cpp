#include "svg.h"

svg::svg() { }

svg::~svg()
{
    if(this->writeOnDestruct) print();
}

void svg::print() const
{
    this->writeOnDestruct = false;
    // todo: print to file
}
