cmake_minimum_required(VERSION 3.10)
project("svgPlot")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -fpermissive -Wall -Wpedantic -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable("${PROJECT_NAME}"
    "main.cpp"
)

add_library(svg
    "svg.h"
    "svg.cpp"
    "LineSpec.h"
    "LineSpec.cpp"
    "polyline.h"
    "polyline.cpp"
    "line.h"
    "line.cpp"
    "svgDrawable.h"
    "svgDrawable.cpp"
    "axis.h"
    "axis.cpp"
    "xAxis.h"
    "xAxis.cpp"
    "yAxis.h"
    "yAxis.cpp"
    "text.h"
    "text.cpp"
)

add_library(svg::svg ALIAS svg)
target_compile_features(svg PUBLIC cxx_std_17)
target_include_directories(svg
	PUBLIC
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
)

# set the startup project in visual studio, such that it is not ALL_BUILD and annoying
if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")
    set(CMAKE_CONFIGURATION_TYPES "Release;Debug;MinSizeRel;RelWithDebInfo")
endif(MSVC)

if(UNIX)
    target_link_libraries ("${PROJECT_NAME}" svg)
endif(UNIX)
