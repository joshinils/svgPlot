#pragma once
#include "axis.h"
#include "line.h"
#include "svg.h"

template<typename D = double>
class XAxis : public Axis<D>
{
public:
    XAxis(const svg& s)
    {
        this->_minVal = s.minX;
        this->_maxVal = s.maxX;

        this->calcValues();

        for(size_t i = 0; i < this->_tickAmount; i++)
        {
            D pos = this->_minVal + i * this->_tickIncrement;
            this->_drawables.emplace_back(std::make_shared<Line<D>>(Line<D>(pos, 0, pos, 0)));
        }
        this->_drawables.emplace_back(std::make_shared<Line<D>>(Line<D>(this->_minVal, 0, this->_maxVal, 0)));
    }
    virtual ~XAxis() = default;

private:
};
