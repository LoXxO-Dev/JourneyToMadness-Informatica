cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.cpp
        sources/utils.hpp
        sources/Producto.cpp
        sources/Producto.hpp
        sources/Bebida.cpp
        sources/Bebida.hpp
        sources/Entrada.cpp
        sources/Entrada.hpp
        sources/PlatoFondo.cpp
        sources/PlatoFondo.hpp
        sources/DetalleComanda.cpp
        sources/DetalleComanda.hpp
        sources/Nodo.cpp
        sources/Nodo.hpp
        sources/Cola.cpp
        sources/Cola.hpp
        sources/Restaurante.cpp
        sources/Restaurante.hpp)
