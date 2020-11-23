#pragma once
#include "axis.h"
#include "svg.h"

template<typename D = double>
class YAxis : public Axis<D>
{
public:
    YAxis(const svg& s)
    {
        this->_minVal = s.minY;
        this->_maxVal = s.maxY;

        this->calcValues();

        for(size_t i = 0; i < this->_tickAmount; i++)
        {
            D pos = this->_minVal + i * this->_tickIncrement;
            this->_drawables.emplace_back(std::make_shared<Line<D>>(Line<D>(0, -pos, 0, -pos)));
        }
        this->_drawables.emplace_back(std::make_shared<Line<D>>(Line<D>(0, -this->_minVal, 0, -this->_maxVal)));
    }
    virtual ~YAxis() = default;

private:
};
