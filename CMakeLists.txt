cmake_minimum_required(VERSION 3.5)
project(mygame)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

add_executable(mygame
  src/main.cpp)

include_directories(inc)

target_link_libraries(mygame PRIVATE SDL2::SDL2)
