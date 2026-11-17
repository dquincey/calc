cmake_minimum_required(VERSION 3.15)
project(calc CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v7.0.3
)
FetchContent_MakeAvailable(ftxui)
file(GLOB SOURCES "src/*.cpp")
add_executable(calc ${SOURCES})
target_include_directories(calc PRIVATE src)
target_link_libraries(calc PRIVATE ftxui::ftxui)
