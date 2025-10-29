cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        funciones/Cliente.cpp
        funciones/Cliente.hpp
        funciones/Utils.hpp
        funciones/Plato.cpp
        funciones/Plato.hpp
        funciones/Restaurante.cpp
        funciones/Restaurante.hpp
)
