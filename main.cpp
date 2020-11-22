#include "svg.h"
#include <iostream>
int main()
{
    svg s;
    int V;

    // clang-format off
    s.plot(V);std::cout << '\n';
    s.plot(V, V);std::cout << '\n';
    s.plot(V, V, V);std::cout << '\n';
    s.plot(V, V, V, V);std::cout << '\n';
    s.plot(V, V, V, V, V);std::cout << '\n';
    s.plot(V, V, V, V, V, V);std::cout << '\n';
    s.plot(V, V, V, V, V, V, V);std::cout << '\n';
    s.plot(V, V, V, V, V, V, V, V);std::cout << '\n';
    // clang-format on

    return 0;
}
