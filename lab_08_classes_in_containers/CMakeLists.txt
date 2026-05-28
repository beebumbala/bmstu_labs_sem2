cmake_minimum_required(VERSION 3.10)

project(MySTLCont CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(STLContDemo main.cpp deposit.cpp)

target_include_directories(STLContDemo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})