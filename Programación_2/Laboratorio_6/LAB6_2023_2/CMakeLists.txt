cmake_minimum_required(VERSION 3.31)
project(LAB_6_2023_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB_6_2023_2 main.cpp
        funciones/ProductoEntregado.cpp
        funciones/ProductoEntregado.hpp
        funciones/utils.hpp
        funciones/Cliente.cpp
        funciones/Cliente.hpp
        funciones/Producto.cpp
        funciones/Producto.hpp
        funciones/Pedido.cpp
        funciones/Pedido.hpp
        funciones/Almacen.cpp
        funciones/Almacen.hpp)
