cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.hpp
        sources/Dron.cpp
        sources/Dron.hpp
        sources/DroneSemaforo.cpp
        sources/DroneSemaforo.hpp
        sources/DroneEstacionamiento.cpp
        sources/DroneEstacionamiento.hpp
        sources/DroneVelocidad.cpp
        sources/DroneVelocidad.hpp
        sources/Nodo.cpp
        sources/Nodo.hpp
        sources/Arbol.cpp
        sources/Arbol.hpp
        sources/Central.cpp
        sources/Central.hpp
        sources/utils.cpp)
