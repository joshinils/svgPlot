#include "line.h"
#include "svg.h"

std::string Line::print(const svg* const s) const
{
    std::stringstream ss;
    ss << std::setprecision(17);
    ss << "<line x1=\"" << this->_x1 << "\" y1=\"" << -this->_y1 << "\" x2=\"" << this->_x2 << "\" y2=\"" << -this->_y2
       << "\" stroke=\"black\" stroke-width=\"" << s->pixelSize << "px\"/>";
    return ss.str();
}
