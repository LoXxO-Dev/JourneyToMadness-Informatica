cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.hpp
        sources/Libro.cpp
        sources/Libro.hpp
        sources/Enciclopedia.cpp
        sources/Enciclopedia.hpp
        sources/Novela.cpp
        sources/Novela.hpp
        sources/Espacio.cpp
        sources/Espacio.hpp
        sources/Estante.cpp
        sources/Estante.hpp
        sources/EstanteVertical.cpp
        sources/EstanteVertical.hpp
        sources/EstanteHorizontal.cpp
        sources/EstanteHorizontal.hpp
        sources/Biblioteca.cpp
        sources/Biblioteca.hpp)
