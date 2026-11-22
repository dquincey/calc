cmake_minimum_required(VERSION 3.14)
project(calc CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(calc src/main.cpp src/draw.cpp src/stack.cpp src/textbox.cpp src/maths.cpp)
