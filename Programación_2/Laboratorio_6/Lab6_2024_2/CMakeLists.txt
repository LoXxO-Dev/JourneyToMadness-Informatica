cmake_minimum_required(VERSION 3.31)
project(Lab6_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6_2024_2 main.cpp
        funciones/utils.hpp
        funciones/Cliente.cpp
        funciones/Cliente.hpp
        funciones/Plato.cpp
        funciones/Plato.hpp
        funciones/Restaurante.cpp
        funciones/Restaurante.hpp)
