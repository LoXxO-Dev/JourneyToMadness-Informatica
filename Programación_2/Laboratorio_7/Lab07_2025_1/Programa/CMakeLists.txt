cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.hpp
        sources/Infraccion.cpp
        sources/Infraccion.hpp
        sources/Drone.cpp
        sources/Drone.hpp
        sources/DroneVelocidad.cpp
        sources/DroneVelocidad.hpp
        sources/DroneSemaforo.cpp
        sources/DroneSemaforo.hpp
        sources/DroneEstacionamiento.cpp
        sources/DroneEstacionamiento.hpp
        sources/Flota.cpp
        sources/Flota.hpp
        sources/CentralDeMonitoreo.cpp
        sources/CentralDeMonitoreo.hpp
        sources/MinisterioDeTransportes.cpp
        sources/MinisterioDeTransportes.hpp
        sources/Comunes.cpp
        sources/Comunes.hpp)
