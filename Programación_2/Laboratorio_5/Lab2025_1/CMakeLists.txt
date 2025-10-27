cmake_minimum_required(VERSION 3.31)
project(Lab2025_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2025_1 main.cpp
        sources/utils.hpp
        sources/BibliotecaGenerica.cpp
        sources/BibliotecaGenerica.hpp
        sources/BibliotecaConductores.cpp
        sources/BibliotecaConductores.hpp
        sources/BibliotecaInfracciones.cpp
        sources/BibliotecaInfracciones.hpp
)
