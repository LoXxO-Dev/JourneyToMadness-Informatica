cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.hpp
        sources/Streams.cpp
        sources/Streams.hpp
        sources/Plataforma.cpp
        sources/Plataforma.hpp
        sources/Categoria.cpp
        sources/Categoria.hpp)
