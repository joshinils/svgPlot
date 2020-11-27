#include "text.h"
#include "svg.h"

Text::Text(double x, double y, const std::string& content)
    : x(x)
    , y(y)
    , content(content)
{ }

std::string Text::print(const svg* const s) const
{
    std::stringstream ss;

    ss << "<text x=\"" << this->x << "\" y=\"" << this->y << "\" font-size=\"" << s->pixelSize * 10 << "px\">"
       << this->content << "</text>";
    return ss.str();
}
