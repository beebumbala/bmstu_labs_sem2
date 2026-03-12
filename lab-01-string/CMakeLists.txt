cmake_minimum_required(VERSION 3.10)

project(MyString CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_library(StringLib STATIC
        string.cpp
)

add_executable(StringDemo
        main.cpp
)

target_link_libraries(StringDemo PRIVATE StringLib)