cmake_minimum_required(VERSION 3.10)

project(MySTLSort CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(STLSortDemo main.cpp deposit.cpp)

target_include_directories(STLSortDemo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})