#include "svg.h"
#include <cmath>
#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& ostr, const std::vector<T>& v)
{
    for(size_t i = 0; i + 1 < v.size(); i++) { ostr << v[i] << ", "; }

    return ostr << v[v.size() - 1];
}

int main()
{
    svg s;

    size_t count  = 1000;
    double minVal = 0;
    double maxVal = std::acos(-1) * 2;
    double range  = maxVal - minVal;
    double dx     = range / (count - 1);

    std::vector<double> x(count);
    std::vector<double> y(count);

    for(size_t i = 0; i < count; i++) { y[i] = std::sin(x[i] = minVal + i * dx); }

    std::cout << maxVal << '\n';
    std::cout << x << '\n';
    std::cout << y << '\n';

    s.plot(x, y);

    return 0;
}
