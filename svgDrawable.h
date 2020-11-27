#pragma once
#include <string>

class svg;

class svgDrawable
{
public:
    virtual ~svgDrawable() = default;

    virtual std::string print(const svg* const s) const = 0;

private:
    /* data */
};
