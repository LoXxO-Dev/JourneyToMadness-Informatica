cmake_minimum_required(VERSION 3.31)
project(Lab6_2025_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6_2025_1 main.cpp
        sources/Infraccion.cpp
        sources/Infraccion.hpp
        sources/Empresa.cpp
        sources/Empresa.hpp
        sources/Multa.cpp
        sources/Multa.hpp
        sources/MinisterioDeTransportes.cpp
        sources/MinisterioDeTransportes.hpp
        sources/utils.hpp)
