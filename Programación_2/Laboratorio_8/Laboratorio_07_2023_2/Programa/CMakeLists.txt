cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.hpp
        sources/Pedido.cpp
        sources/Pedido.hpp
        sources/PrioridadAlta.cpp
        sources/PrioridadAlta.hpp
        sources/PrioridadMedia.cpp
        sources/PrioridadMedia.hpp
        sources/PrioridadBaja.cpp
        sources/PrioridadBaja.hpp
        sources/OrdenVenta.cpp
        sources/OrdenVenta.hpp
        sources/Almacen.cpp
        sources/Almacen.hpp)
