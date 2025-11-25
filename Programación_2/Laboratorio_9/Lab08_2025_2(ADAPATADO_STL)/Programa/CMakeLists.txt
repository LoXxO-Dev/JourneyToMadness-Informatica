cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.cpp
        sources/utils.hpp
        sources/Metrica.cpp
        sources/Metrica.hpp
        sources/MetricaBasica.cpp
        sources/MetricaBasica.hpp
        sources/MetricaEngagement.cpp
        sources/MetricaEngagement.hpp
        sources/MetricaCalidad.cpp
        sources/MetricaCalidad.hpp
        sources/AdministrarMetricas.cpp
        sources/AdministrarMetricas.hpp)
