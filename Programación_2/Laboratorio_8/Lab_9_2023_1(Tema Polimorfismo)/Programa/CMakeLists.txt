cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        funciones/Alumno.cpp
        funciones/Alumno.hpp
        funciones/utils.hpp
        funciones/Escala.cpp
        funciones/Escala.hpp
        funciones/Presencial.cpp
        funciones/Presencial.hpp
        funciones/Semipresencial.cpp
        funciones/Semipresencial.hpp
        funciones/Virtual.cpp
        funciones/Virtual.hpp
        funciones/Boleta.cpp
        funciones/Boleta.hpp
        funciones/Tesoreria.cpp
        funciones/Tesoreria.hpp)
