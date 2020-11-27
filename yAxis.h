#pragma once
#include "axis.h"
#include "svg.h"

class YAxis : public Axis
{
public:
    YAxis(const svg& s)
    {
        this->_minVal = s.minY;
        this->_maxVal = s.maxY;

        this->calcValues();

        for(size_t i = 0; i < this->_tickAmount; i++)
        {
            double pos = this->_minVal + i * this->_tickIncrement;
            this->_drawables.emplace_back(std::make_shared<Line>(Line(s.pixelSize * 5, -pos, -s.pixelSize * 10, -pos)));
            this->_drawables.emplace_back(
            std::make_shared<Text>(Text(s.pixelSize * 2 * 5, pos + s.pixelSize * 3, std::to_string(pos))));
        }
        this->_drawables.emplace_back(std::make_shared<Line>(Line(0, -this->_minVal, 0, -this->_maxVal)));
    }
    virtual ~YAxis() = default;

private:
};
