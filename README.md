# svgPlot

This C++ library can plot `std::vector<double>`s to an svg file.
## to download (clone with `git`):
```bash
git clone --recurse-submodules -j8 https://github.com/joshinils/svgPlot
cd svgPlot
```

## to make (with cmake >=3.10):
``` bash
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j "$(nproc)" svgPlot
cd ..
```
(cmake needs a C++ compiler)

## to run; the executable is now located in the `build` directory, named `svgPlot`:
```bash
build/svgPlot
```
This will run my `main.cpp` with "testing content" from ongoing development.

## to use in your project:
1. Add this code to yours; as a submodule in your repository (`git submodule add https://github.com/joshinils/svgPlot`), or clone it, or copy the code to `./svgPlot`.  
2. Tell cmake to use this library; add this to your `CmakeLists.txt`:
```cmake
add_subdirectory(svgPlot)
target_link_libraries ("${PROJECT_NAME}" PUBLIC svg)
```
3. Look at [`main.cpp`](main.cpp) for examples on how to use this.
4. Make your project as before, cmake will build the library for you and link it.

## implemented features
- Plot a `std::vector<double>` against its index.
- Plot a `std::vector<double>` against another as a line-plot.
- Plot a multiple of pairs of `std::vector<double>` against each other as a line-plot.

## planned features
Specify colors of lines, style of lines, no lines, axis style, grid-background, axis tick spacing and other settings.

<br/><br/><br/>
P.S.: Do tell me if there are missing libraries I used that you needed to install so I can list them here.
