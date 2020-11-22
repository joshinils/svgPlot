#include "LineSpec.h"
#include <iostream>

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

        // todo delegate plot to plot with generated index vector as x arg
        plot(y, y, ls); // stand-in
    }

    template<typename V, typename... Param>
    void plot(const V& y1, const LineSpec& ls1, const Param&... params)
    {
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " rec single \\w ls\n";
        plot(y1, ls1);
        plot(params...);
    }

    //void plot() { std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << " empty case\n"; }

private:
    mutable bool writeOnDestruct = true;
};
