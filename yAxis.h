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

        double xPos = s.minX - s.pixelSize * 10;
        for(size_t i = 0; i < this->_tickAmount; i++)
        {
            double pos = -(this->_minVal + i * this->_tickIncrement);
            this->_drawables.emplace_back(
            std::make_shared<Line>(Line(xPos + s.pixelSize * 5, -pos, xPos - s.pixelSize * 5, -pos)));
            this->_drawables.emplace_back(
            std::make_shared<Text>(Text(xPos - s.pixelSize * 2 * 5, pos + s.pixelSize * 3, std::to_string(-pos), -90)));
        }
        this->_drawables.emplace_back(std::make_shared<Line>(Line(xPos, this->_minVal, xPos, this->_maxVal)));
    }
    virtual ~YAxis() = default;

private:
};
