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
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
    }

    template<typename V>
    void plot_pairs(const V& x, const V& y, const LineSpec& ls = LineSpec())
    {
        // base case for pairs
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot(x, y, ls); // delegate to implementation
    }


    /* plots multiple X, Y pairs using the same axes for all lines. */
    template<typename V, typename... Param>
    void plot(const V& x1, const V& y1, const Param&... params)
    {
        // entry for pairs without linespec
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot_pairs(x1, y1, params...);
    }

    template<typename V, typename... Param>
    void plot_pairs(const V& x1, const V& y1, const Param&... params)
    {
        // peel off pair
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot_pairs(x1, y1);
        plot_pairs(params...);
    }

    /* sets the line style, marker type, and color for each line. You can mix X, Y, LineSpec triplets with X, Y pairs.
     * For example, plot(X1, Y1, X2, Y2, LineSpec2, X3, Y3). */
    template<typename V, typename... Param>
    void plot(const V& x1, const V& y1, const LineSpec& ls1, const Param&... params)
    {
        // entry case for pairs with LineSpec
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot_pairs(x1, y1, ls1, params...);
    }

    template<typename V, typename... Param>
    void plot_pairs(const V& x1, const V& y1, const LineSpec& ls1, const Param&... params)
    {
        // peel off pair with LineSpec
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot_pairs(x1, y1, ls1);
        plot_pairs(params...);
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
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
    }

    template<typename V>
    void plot_single(const V& y, const LineSpec& ls = LineSpec())
    {
        // base case for single
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot(y, ls); // delegate to implementation
    }


    template<typename V, typename... Param>
    void plot(const V& y1, const Param&... params)
    {
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot_single(y1);
        plot_single(params...);
    }

    template<typename V, typename... Param>
    void plot_single(const V& y1, const Param&... params)
    {
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot_single(y1);
        plot_single(params...);
    }

    template<typename V, typename... Param>
    void plot(const V& y1, const LineSpec& ls1 = LineSpec(), const Param&... params)
    {
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot_single(y1, ls1);
        plot_single(params...);
    }

    template<typename V, typename... Param>
    void plot_single(const V& y1, const LineSpec& ls1 = LineSpec(), const Param&... params)
    {
        std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n';
        plot_single(y1, ls1);
        plot_single(params...);
    }

    void plot() { std::cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << '\n'; }

private:
    mutable bool writeOnDestruct = true;
};
