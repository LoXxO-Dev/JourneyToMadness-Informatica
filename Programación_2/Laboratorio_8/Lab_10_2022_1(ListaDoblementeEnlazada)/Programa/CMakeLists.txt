cmake_minimum_required(VERSION 3.31)
project(Programa)

set(CMAKE_CXX_STANDARD 20)

add_executable(Programa main.cpp
        sources/utils.cpp
        sources/utils.hpp
        sources/Pedido.cpp
        sources/Pedido.hpp
        sources/PedidoEspecial.cpp
        sources/PedidoEspecial.hpp
        sources/PedidoUsual.cpp
        sources/PedidoUsual.hpp
        sources/PedidoEventual.cpp
        sources/PedidoEventual.hpp
        sources/Nodo.cpp
        sources/Nodo.hpp
        sources/Lista.cpp
        sources/Lista.hpp
        sources/Promociones.cpp
        sources/Promociones.hpp)
