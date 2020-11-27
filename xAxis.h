#pragma once
#include "axis.h"
#include "line.h"
#include "svg.h"
#include "text.h"

class XAxis : public Axis
{
public:
    XAxis(const svg& s)
    {
        this->_minVal = s.minX;
        this->_maxVal = s.maxX;

        this->calcValues();

        double yPos = s.minY - s.pixelSize * 10;
        for(size_t i = 0; i < this->_tickAmount; i++)
        {
            double pos = this->_minVal + i * this->_tickIncrement;
            this->_drawables.emplace_back(
            std::make_shared<Line>(Line(pos, yPos + s.pixelSize * 5, pos, yPos - s.pixelSize * 5)));
            this->_drawables.emplace_back(
            std::make_shared<Text>(Text(pos - s.pixelSize * 3, -yPos + s.pixelSize * 3 * 5, std::to_string(pos))));
        }
        this->_drawables.emplace_back(std::make_shared<Line>(Line(this->_minVal, yPos, this->_maxVal, yPos)));
    }
    virtual ~XAxis() = default;

private:
};
