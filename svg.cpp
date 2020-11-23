#include "svg.h"
#include "xAxis.h"
#include "yAxis.h"
#include <fstream>

svg::svg() { }

svg::~svg()
{
    if(this->writeOnDestruct) print();
}

void svg::print() const
{
    this->writeOnDestruct = false;

    std::ofstream fout("filename.svg");
    if(!fout) throw "could not open file to write into!";

    fout << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n<svg ";
    if(this->apparentWidth > 0) fout << "width=\"" << this->apparentWidth << "px\" ";
    if(this->apparentHeight > 0) fout << "height=\"" << this->apparentHeight << "px\" ";


    fout << "viewBox=\"" << this->minX << ' ' << -this->maxY << ' ' << this->maxX - this->minX << ' '
         << this->maxY - this->minY << "\" ";


    fout << "xmlns=\"http://www.w3.org/2000/svg\">\n";
    { // print content
        for(const auto& d : this->drawables) { fout << d->print() << '\n'; }

        XAxis xAxis(*this);
        YAxis yAxis(*this);
        fout << xAxis.print() << '\n';
        fout << yAxis.print() << '\n';
    }
    fout << "</svg>";


    fout.close();
}
