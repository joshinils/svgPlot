#pragma once
#include "svgDrawable.h"
#include <iomanip>
#include <sstream>
#include <vector>

class svg;

class Line : public svgDrawable
{
public:
    Line() { }

    Line(double x1, double y1, double x2, double y2)
        : _x1(x1)
        , _y1(y1)
        , _x2(x2)
        , _y2(y2)
    { }

    ~Line() = default;

    virtual std::string print(const svg* const s) const override;

private:
    double _x1;
    double _y1;
    double _x2;
    double _y2;
};
