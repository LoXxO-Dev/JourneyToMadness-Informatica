cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        funciones/utils.hpp
        funciones/Producto.cpp
        funciones/Producto.hpp
        funciones/Bebida.cpp
        funciones/Bebida.hpp
        funciones/Entrada.cpp
        funciones/Entrada.hpp
        funciones/PlatoFondo.cpp
        funciones/PlatoFondo.hpp
        funciones/Comanda.cpp
        funciones/Comanda.hpp
        funciones/Restaurante.cpp
        funciones/Restaurante.hpp)
