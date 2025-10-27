cmake_minimum_required(VERSION 3.31)
project(Lab5_2023_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab5_2023_2 main.cpp
        sources/utils.hpp
        sources/PilaConEnteros.cpp
        sources/PilaConEnteros.hpp
        sources/PilaConRegistros.cpp
        sources/PilaConRegistros.hpp
        sources/FlotaGenerica.cpp
        sources/FlotaGenerica.hpp)
