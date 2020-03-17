cmake_minimum_required(VERSION 3.15)
project(Geometry)

set(CMAKE_CXX_STANDARD 17)
set(GOOGLETEST_VERSION 1.10.0) # from googletest-master/CML.txt

add_executable(Geometry src/main.cpp src/Point.cpp src/Point.h src/Shapes.cpp src/Shapes.h) # main

add_subdirectory(external/googletest)
include_directories(src
        external/googletest/include)

# Test: class Coordinate & class Point
add_executable(TestPoint
        test/testPoint.cpp
        src/Point.cpp
        external/googletest)
target_link_libraries(TestPoint gtest_main)

# Test: class Line & class Circle & variant Geometry & intersections<Shape1, Shape2>
add_executable(TestShapes
        test/testShapes.cpp
        src/Shapes.cpp
        src/Point.cpp
        external/googletest)
target_link_libraries(TestShapes gtest_main)