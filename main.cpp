#include "svg.h"
#include <iostream>
int main()
{
    svg s;
    int V;
    LineSpec L;

    // clang-format off
    
    s.plot(V);std::cout << '\n';
    s.plot(V, L);std::cout << '\n';

    // s.plot(V, V, V);std::cout << '\n';
    // s.plot(V, V, V, V, V);std::cout << '\n';
    // s.plot(V, V, V, V, V, V, V);std::cout << '\n';

    std::cout << "\n\n\n";

    s.plot(V, V);std::cout << '\n';
    s.plot(V, V, L);std::cout << '\n';

    std::cout << "\n\n\n";

    s.plot(V, L, V, L, V, L);std::cout << '\n';
    s.plot(V, L, V, L, V, L, V, L, V, L);std::cout << '\n';
    s.plot(V, L, V, L, V, L, V, L, V, L, V, L);std::cout << '\n';

    std::cout << "\n\n\n";

    s.plot(V, V,    V, V   );std::cout << '\n';
    s.plot(V, V,    V, V, L);std::cout << '\n';
    s.plot(V, V, L, V, V   );std::cout << '\n';
    s.plot(V, V, L, V, V, L);std::cout << '\n';

    std::cout << "\n\n\n";

    s.plot(V, V,    V, V,    V, V   );std::cout << '\n';
    s.plot(V, V,    V, V,    V, V, L);std::cout << '\n';
    s.plot(V, V,    V, V, L, V, V   );std::cout << '\n';
    s.plot(V, V,    V, V, L, V, V, L);std::cout << '\n';
    s.plot(V, V, L, V, V,    V, V   );std::cout << '\n';
    s.plot(V, V, L, V, V,    V, V, L);std::cout << '\n';
    s.plot(V, V, L, V, V, L, V, V   );std::cout << '\n';
    s.plot(V, V, L, V, V, L, V, V, L);std::cout << '\n';

    // clang-format on

    return 0;
}
