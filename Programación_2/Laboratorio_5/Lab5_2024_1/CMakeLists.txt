cmake_minimum_required(VERSION 3.31)
project(Lab5_2024_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab5_2024_1 main.cpp
        sources/utils.hpp
        sources/BibliotecaGenerica.cpp
        sources/BibliotecaGenerica.hpp
        sources/FuncionesEnteras.cpp
        sources/FuncionesEnteras.hpp
        sources/FuncionesRegistros.cpp
        sources/FuncionesRegistros.hpp)
