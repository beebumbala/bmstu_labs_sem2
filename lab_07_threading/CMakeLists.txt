cmake_minimum_required(VERSION 3.10)

project(MyThreading CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ThrDemo v_threading.cpp)
add_executable(AscDemo v_async.cpp)
add_executable(MtxDemo v_mutex.cpp)
