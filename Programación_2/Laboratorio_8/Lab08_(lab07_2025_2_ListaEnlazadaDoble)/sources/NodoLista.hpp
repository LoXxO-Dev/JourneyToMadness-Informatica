//
// Created by User on 20/11/2025.
//

#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP


#include "utils.hpp"

class NodoLista {
private:
    class Streamer *streamer;
    class NodoLista *sig;
    class NodoLista *ant;

public:
    NodoLista();
    friend class ListaDoble;
};


#endif //NODOLISTA_HPP
