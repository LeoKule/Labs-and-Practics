cmake_minimum_required(VERSION 3.24)
project(Practic4)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc/")

add_executable(Practic4 main.cpp Device.cpp inc/Device.h)

file(COPY devices.txt DESTINATION /)