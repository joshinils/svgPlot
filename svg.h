#pragma once
#include "LineSpec.h"
#include "line.h"
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

/* to construct an svg image.
 * if any element is added the destructor will automatically print to file.
 * If you print earlier, the destructor will no longer print to file. */
class svg
{
public:
    svg();
    ~svg();

    void print() const;

    /* creates a 2-D line plot of the data in Y versus the corresponding values in X.
     *
     * LineSpec sets the line style, marker symbol, and color. */
    template<typename V>
    void plot(const V& x, const V& y, const LineSpec& ls = LineSpec())
    {
        // base case for pairs
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " base case double\n";

        // todo implement plot

        for(const auto& xElem : x)
        {
            this->maxX = std::max(this->maxX, xElem);
            this->minX = std::min(this->minX, xElem);
        }

        for(const auto& yElem : y)
        {
            this->maxY = std::max(this->maxY, yElem);
            this->minY = std::min(this->minY, yElem);
        }

        for(size_t i = 0; i + 1 < std::min(x.size(), y.size()); i++)
        {
            auto b = Line<double>(x[i], y[i], x[i + 1], y[i + 1]);
            auto a = std::make_shared<Line<double>>(b);
            this->drawables.emplace_back(a);
        }
    }

    template<typename V>
    void plot(const V& x1, const V& y1, const LineSpec& ls1, const V& x2, const V& y2, const LineSpec& ls2 = LineSpec())
    {
        // base case for 2 pairs
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " base case double, p ls, p ls\n";
        plot(x1, y1, ls1); // delegate to implementation
        plot(x2, y2, ls2); // delegate to implementation
    }

    /* plots multiple X, Y pairs using the same axes for all lines. */
    template<typename V, typename... Param>
    void plot(const V& x1, const V& y1, const V& x2, const V& y2, const Param&... params)
    {
        // entry for pairs without linespec
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " rec double, p, p, ... \n";
        // todo use linespec at end in parameter pack, not default linespec
        plot(x1, y1, LineSpec()); // peel off pair

        plot(x2, y2, params...);
    }

    template<typename V>
    void plot(const V& x1, const V& y1, const V& x2, const V& y2, const LineSpec& ls = LineSpec())
    {
        // base case for 2 pairs, overall linespec
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " base case double, p, p ls\n";
        plot(x1, y1, ls); // delegate to implementation
        plot(x2, y2, ls); // delegate to implementation
    }

    template<typename V, typename... Param>
    void plot(const V& x1, const V& y1, const LineSpec& ls1, const V& x2, const V& y2, const Param&... params)
    {
        // entry for pairs with linespec
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " rec double, p ls, p, ... \n";
        plot(x1, y1, ls1); // peel off pair

        plot(x2, y2, params...);
    }

    /* sets the line style, marker type, and color for each line. You can mix X, Y, LineSpec triplets with X, Y pairs.
     * For example, plot(X1, Y1, X2, Y2, LineSpec2, X3, Y3). */
    template<typename V, typename... Param>
    void plot(const V& x1,
              const V& y1,
              const LineSpec& ls1,
              const V& x2,
              const V& y2,
              const LineSpec& ls2,
              const Param&... params)
    {
        // entry for pairs with linespec
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " rec double, p ls, p ls, ... \n";
        plot(x1, y1, ls1); // peel off pair

        plot(x2, y2, ls2, params...);
    }

    /*creates a 2-D line plot of the data in Y versus the index of each value.
     *
     * If Y is a vector, then the x-axis scale ranges from 1 to length(Y).
     *
     * LineSpec sets the line style, marker symbol, and color. */
    template<typename V>
    void plot(const V& y, const LineSpec& ls = LineSpec())
    {
        // base case for single
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " base case single\n";

        V x(y);
        for(size_t i = 0; i < y.size(); i++) { x[i] = i; }

        plot(x, y, ls);
    }

    template<typename V, typename... Param>
    void plot(const V& y1, const LineSpec& ls1, const Param&... params)
    {
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " rec single \\w ls\n";
        plot(y1, ls1);
        plot(params...);
    }

    //void plot() { std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " empty case\n"; }

    void addDrawable(std::shared_ptr<svgDrawable> p) { this->drawables.emplace_back(p); }

private:
    mutable bool writeOnDestruct = true;

    template<typename T>
    friend class Axis;
    template<typename T>
    friend class XAxis;
    template<typename T>
    friend class YAxis;

    // axis limits
    double minX = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::min();
    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::min();

    double apparentWidth  = 1000;
    double apparentHeight = 1000;

    std::vector<std::shared_ptr<svgDrawable>> drawables;
};
