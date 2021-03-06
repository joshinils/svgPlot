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
    {
        svg s("filename1.svg");

        // generate data to plot
        size_t count  = 100;
        double minVal = 0 - 1;
        double maxVal = std::acos(-1) * 2 - 1;
        double range  = maxVal - minVal;
        double dx     = range / (count - 1);

        std::vector<double> x(count);
        std::vector<double> y(count);

        for(size_t i = 0; i < count; i++) { y[i] = std::sin(x[i] = minVal + i * dx) * .5 + 120; }

        // print data to plot
        std::cout << maxVal << '\n';
        std::cout << x << '\n';
        std::cout << y << '\n';

        // plot data
        s.plot(x, y);

        // svg s will write to file from the destructor
    }

    {
        svg s("filename2.svg");

        // generate data to plot
        size_t count  = 100;
        double minVal = 0 - 1;
        double maxVal = std::acos(-1) * 2 - 1;
        double range  = maxVal - minVal;
        double dx     = range / (count - 1);

        std::vector<double> x(count);
        std::vector<double> y(count);

        for(size_t i = 0; i < count; i++) { y[i] = std::sin(x[i] = minVal + i * dx) * 50 + 120; }

        // print data to plot
        std::cout << maxVal << '\n';
        std::cout << x << '\n';
        std::cout << y << '\n';

        // plot data
        s.plot(x, y);

        // svg s will write to file from the destructor
    }

    return 0;
}
