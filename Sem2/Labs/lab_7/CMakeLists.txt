cmake_minimum_required(VERSION 3.24)
project(lab_7)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc/" "src/")

add_executable(lab_7 main.cpp src/Shape.cpp inc/Shape.h src/Triangle.cpp inc/Triangle.h src/Rectangle.cpp inc/Rectangle.h src/Circle.cpp inc/Circle.h)
