cmake_minimum_required(VERSION 3.10)

project(MyExceptions CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ExcDemo main.cpp date.cpp)

target_include_directories(ExcDemo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})