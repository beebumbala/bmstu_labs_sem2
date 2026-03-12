cmake_minimum_required(VERSION 3.10)

project(MyVector CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(VecLib STATIC
        vector.cpp
)

add_executable(VecDemo
        main.cpp
)

target_link_libraries(VecDemo PRIVATE VecLib)