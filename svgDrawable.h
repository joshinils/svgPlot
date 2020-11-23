#include <string>

class svgDrawable
{
public:
    virtual ~svgDrawable() = default;

    virtual std::string print() const = 0;

private:
    /* data */
};
