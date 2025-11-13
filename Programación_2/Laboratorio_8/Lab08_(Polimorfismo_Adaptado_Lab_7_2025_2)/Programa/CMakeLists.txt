cmake_minimum_required(VERSION 3.31)
project(Lab08_2025_1_Ayudin_)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab08_2025_1_Ayudin_ main.cpp
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
        sources/Streamer.cpp
        sources/Streamer.hpp
        sources/StreamerGratuito.cpp
        sources/StreamerGratuito.hpp
        sources/StreamerPago.cpp
        sources/StreamerPago.hpp
        sources/Nodo.cpp
        sources/Nodo.hpp
        sources/Arbol.cpp
        sources/Arbol.hpp
        sources/GestorStreamers.cpp
        sources/GestorStreamers.hpp)
