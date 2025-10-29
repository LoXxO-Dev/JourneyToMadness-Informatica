cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        funciones/Infraccion.cpp
        funciones/Infraccion.hpp
        funciones/utils.hpp
        funciones/Empresa.cpp
        funciones/Empresa.hpp
        funciones/Multa.cpp
        funciones/Multa.hpp
        funciones/MinisterioDeTransporte.cpp
        funciones/MinisterioDeTransporte.hpp)
