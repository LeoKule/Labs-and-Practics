cmake_minimum_required(VERSION 3.24)
project(lab_6)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc/")

add_executable(lab_6 main.cpp Logger.cpp inc/Logger.h)
