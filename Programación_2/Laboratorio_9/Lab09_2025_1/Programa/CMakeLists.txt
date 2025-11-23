cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.cpp
        sources/utils.hpp
        sources/Infraccion.cpp
        sources/Infraccion.hpp
        sources/Vehiculo.cpp
        sources/Vehiculo.hpp
        sources/Multa.cpp
        sources/Multa.hpp
        sources/Empresa.cpp
        sources/Empresa.hpp
        sources/MinisterioDeTransporte.cpp
        sources/MinisterioDeTransporte.hpp)
