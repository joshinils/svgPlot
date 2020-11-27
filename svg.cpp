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

    double pixelWidth  = (this->maxX - this->minX) / this->apparentWidth;
    double pixelHeight = (this->maxY - this->minY) / this->apparentHeight;

    std::cout << "pixelWidth  " << pixelWidth << '\n';
    std::cout << "pixelHeight " << pixelHeight << '\n';

    pixelSize = std::max(pixelWidth, pixelHeight);

    XAxis xAxis(*this);
    YAxis yAxis(*this);

    fout << "viewBox=\"" << this->minX << ' ' << -this->maxY << ' ' << this->maxX - this->minX << ' '
         << this->maxY - this->minY << "\" ";


    fout << "xmlns=\"http://www.w3.org/2000/svg\">\n";
    { // print content
        for(const auto& d : this->drawables) { fout << d->print(this) << '\n'; }

        fout << xAxis.print(this) << '\n';
        fout << yAxis.print(this) << '\n';
    }
    fout << "</svg>";


    fout.close();
}
