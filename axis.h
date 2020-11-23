#pragma once
#include "svgDrawable.h"
#include <memory>
#include <sstream>
#include <vector>

template<typename D = double>
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

    virtual std::string print() const override
    {
        std::stringstream ss;
        for(const auto& e : this->_drawables) ss << e->print();
        return ss.str();
    }

protected:
    D _minVal;
    D _maxVal;
    D _span;
    size_t _tickAmount;
    D _tickIncrement;
    D _width;

    std::vector<std::shared_ptr<svgDrawable>> _drawables;
};
