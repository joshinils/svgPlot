#include "svgDrawable.h"
class Text : public svgDrawable
{
public:
    Text(double x, double y, const std::string& content);
    virtual ~Text() = default;

    virtual std::string print(const svg* const s) const override;

private:
    double x;
    double y;
    std::string content;
};
