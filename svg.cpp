#include "svg.h"
#include <fstream>

svg::svg() { }

svg::~svg()
{
    if(this->writeOnDestruct) print();
}

void svg::print() const
{
    this->writeOnDestruct = false;
    // todo: print to file

    std::ofstream fout("filename.svg");
    if(!fout) throw "could not open file to write into!";

    fout << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n<svg ";
    if(this->apparentWidth > 0) fout << "width=" << this->apparentWidth << ' ';
    if(this->apparentHeight > 0) fout << "height=" << this->apparentHeight << ' ';
    fout << "viewBox=\"" << this->minX << ' ' << -this->maxY << ' ' << this->maxX - this->minX << ' '
         << this->maxY - this->minY << "\" ";
    fout << "xmlns=\"http://www.w3.org/2000/svg\">\n";
    for(const auto& d : this->drawables) { fout << d->print() << '\n'; }
    fout << "</svg>";

    fout.close();
}
