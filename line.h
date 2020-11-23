#include "svgDrawable.h"
#include <iomanip>
#include <sstream>
#include <vector>

template<typename V>
class line : public svgDrawable
{
public:
    line() { }

    line(const V& x1, const V& y1, const V& x2, const V& y2)
        : _x1(x1)
        , _y1(y1)
        , _x2(x2)
        , _y2(y2)
    { }

    ~line() = default;

    virtual std::string print() const override
    {
        std::stringstream ss;
        ss << std::setprecision(17);
        ss << "<line x1=\"" << this->_x1 << "\" y1=\"" << -this->_y1 << "\" x2=\"" << this->_x2 << "\" y2=\""
           << -this->_y2 << "\" stroke=\"black\" stroke-width=\"1px\"/>";
        return ss.str();
    }

private:
    V _x1;
    V _y1;
    V _x2;
    V _y2;
};
