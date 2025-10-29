cmake_minimum_required(VERSION 3.31)


set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        funciones/utils.hpp
        funciones/alumnonota.cpp
        funciones/alumnonota.hpp
        funciones/nota.cpp
        funciones/nota.hpp
        funciones/alumno.cpp
        funciones/alumno.hpp
        funciones/sources.cpp
        funciones/sources.hpp)
