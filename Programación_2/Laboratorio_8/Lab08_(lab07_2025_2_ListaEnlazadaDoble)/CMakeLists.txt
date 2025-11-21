cmake_minimum_required(VERSION 3.31)
project(Lab08__lab07_2025_2_ListaCicularDoble_)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab08__lab07_2025_2_ListaCicularDoble_ main.cpp
        sources/utils.cpp
        sources/utils.hpp
        sources/Metrica.cpp
        sources/Metrica.hpp
        sources/MetricaBasica.cpp
        sources/MetricaBasica.hpp
        sources/MetricaEngament.cpp
        sources/MetricaEngament.hpp
        sources/MetricaCalidad.cpp
        sources/MetricaCalidad.hpp
        sources/Streamer.cpp
        sources/Streamer.hpp
        sources/StreamerGratuito.cpp
        sources/StreamerGratuito.hpp
        sources/StreamerPago.cpp
        sources/StreamerPago.hpp
        sources/GestorStreamers.cpp
        sources/GestorStreamers.hpp
        sources/NodoLista.cpp
        sources/NodoLista.hpp
        sources/ListaDoble.cpp
        sources/ListaDoble.hpp)
