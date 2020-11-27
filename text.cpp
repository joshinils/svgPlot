#include "text.h"
#include "svg.h"

Text::Text(double x, double y, const std::string& content, double degrees /* = 0*/)
    : x(x)
    , y(y)
    , content(content)
    , degrees(degrees)
    , cx(x)
    , cy(y)
{ }

std::string Text::print(const svg* const s) const
{
    std::stringstream ss;

    ss << "<text x=\"" << this->x << "\" y=\"" << this->y << "\" font-size=\"" << s->pixelSize * 10 << "px\"";
    if(degrees != 0) ss << " transform=\"rotate(" << degrees << ", " << cx << ", " << cy << ")\"";
    ss << "> " << this->content << "</text>";
    return ss.str();
}
