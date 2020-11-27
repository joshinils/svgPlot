#pragma once
#include "svgDrawable.h"
#include <exception>
#include <sstream>

template<typename V>
class polyline : public svgDrawable
{
public:
    polyline() { }

    polyline(const V& x, const V& y)
        : _x(x)
        , _y(y)
    {
        if(_x.size() != y.size())
            throw std::invalid_argument(std::string(__FILE__) + ":" + std::to_string(__LINE__) + " : "
                                        + __PRETTY_FUNCTION__ + " arguments are not the same size!");
    }

    ~polyline() = default;

    virtual std::string print(const svg* const s) const override
    {
        std::stringstream ss;
        ss << "<polyline points=\"";
        for(size_t i = 0; i + 1 < _x.size(); i++) { ss << _x[i] << ',' << _y[i] << ' '; }
        if(_x.size() > 0) ss << _x[_x.size() - 1] << ',' << -_y[_y.size() - 1];
        ss << "\"/>";
        return ss.str();
    }

private:
    V _x;
    V _y;
};
