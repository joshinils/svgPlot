#include "svg.h"
#include "xAxis.h"
#include "yAxis.h"
#include <fstream>

svg::svg(const std::string& fileName)
    : filename(fileName)
{
    // remove extension, if given
    if(size_t s = filename.size();
       s >= 4 && filename[s - 4] == '.' && filename[s - 3] == 's' && filename[s - 2] == 'v' && filename[s - 1] == 'g')
    {
        filename.pop_back();
        filename.pop_back();
        filename.pop_back();
        filename.pop_back();
    }
}

svg::~svg()
{
    if(this->writeOnDestruct) print();
}

void svg::print() const
{
    this->writeOnDestruct = false;

    std::ofstream fout(filename + ".svg");
    if(!fout) throw "could not open file to write into!";

    double pixelWidth  = (this->maxX - this->minX) / this->apparentWidth;
    double pixelHeight = (this->maxY - this->minY) / this->apparentHeight;

    std::cout << "pixelWidth  " << pixelWidth << '\n';
    std::cout << "pixelHeight " << pixelHeight << '\n';

    pixelSize = std::max(pixelWidth, pixelHeight);

    fout << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n<svg ";

    if(this->apparentWidth > 0) fout << "width=\"" << this->apparentWidth << "px\" ";
    if(this->apparentHeight > 0) fout << "height=\"" << this->apparentHeight << "px\" ";


    XAxis xAxis(*this);
    YAxis yAxis(*this);

    fout << "viewBox=\"" << this->minX - pixelSize * 40 << ' ' << -(this->maxY + pixelSize * 70) << ' '
         << this->maxX - this->minX + pixelSize * 100 << ' ' << this->maxY - this->minY + pixelSize * 110 << "\" ";


    fout << "xmlns=\"http://www.w3.org/2000/svg\">\n";
    { // print content
        for(const auto& d : this->drawables) { fout << d->print(this) << '\n'; }

        fout << xAxis.print(this) << '\n';
        fout << yAxis.print(this) << '\n';
    }
    fout << "</svg>";


    fout.close();
}
