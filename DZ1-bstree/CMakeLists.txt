cmake_minimum_required(VERSION 3.10)

project(MyBSTree CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(BSTreeDemo main.cpp bstree.cpp)

target_include_directories(BSTreeDemo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})