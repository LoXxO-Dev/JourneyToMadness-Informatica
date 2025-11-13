//
// Created by User on 11/11/2025.
//

#ifndef NODO_HPP
#define NODO_HPP

#include "utils.hpp"
#include "Arbol.hpp"
class Nodo {
private:
    class Streamer *dato;
    class Nodo *izq;
    class Nodo *der;

public:
    Nodo();
    friend class Arbol;
};


#endif //NODO_HPP
