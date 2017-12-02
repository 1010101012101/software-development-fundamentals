cmake_minimum_required(VERSION 3.8)
project(Assn5_15rws)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ShapesGood_15rws.h ShapesGood_15rws.cpp TestGoodShapes.cpp ShapesBad.cpp ShapesBad.h TestBadShapes.cpp)
add_executable(Assn5_15rws ${SOURCE_FILES})