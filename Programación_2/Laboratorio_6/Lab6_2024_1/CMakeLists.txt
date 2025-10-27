cmake_minimum_required(VERSION 3.31)
project(Lab6_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6_2024_1 main.cpp
        funciones/utils.hpp
        funciones/Libro.cpp
        funciones/Libro.hpp
        funciones/Espacio.cpp
        funciones/Espacio.hpp
        funciones/Estate.cpp
        funciones/Estate.hpp
        funciones/Biblioteca.cpp
        funciones/Biblioteca.hpp)
