#pragma once
#include "svgDrawable.h"
#include <memory>
#include <sstream>
#include <vector>

class Axis : public svgDrawable
{
public:
    Axis(){};
    virtual ~Axis() = default;

    void calcValues()
    {
        this->_tickAmount = 5;
        this->_span       = this->_maxVal - this->_minVal;

        this->_tickIncrement = this->_span / (this->_tickAmount - 1);
        this->_width         = this->_span / 10;
    }

    virtual std::string print(const svg* const s) const override
    {
        std::stringstream ss;
        for(const auto& e : this->_drawables) ss << e->print(s);
        return ss.str();
    }

protected:
    double _minVal;
    double _maxVal;
    double _span;
    size_t _tickAmount;
    double _tickIncrement;
    double _width;

    std::vector<std::shared_ptr<svgDrawable>> _drawables;
};
