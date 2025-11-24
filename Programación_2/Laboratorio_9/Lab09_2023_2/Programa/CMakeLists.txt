cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.cpp
        sources/utils.hpp
        sources/NPedido.cpp
        sources/NPedido.hpp
        sources/Vehiculo.cpp
        sources/Vehiculo.hpp
        sources/Camion.cpp
        sources/Camion.hpp
        sources/Furgon.cpp
        sources/Furgon.hpp
        sources/NVehiculo.cpp
        sources/NVehiculo.hpp
        sources/Flota.cpp
        sources/Flota.hpp)
