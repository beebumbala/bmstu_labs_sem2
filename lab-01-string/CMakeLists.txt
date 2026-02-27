# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(MyString CXX)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Добавляем папку с заголовками
include_directories(include)

# Создаем библиотеку из исходников
add_library(StringLib STATIC
        string.cpp
)

# Создаем исполняемый файл
add_executable(StringDemo
        main.cpp
)

# Связываем библиотеку с программой
target_link_libraries(StringDemo PRIVATE StringLib)