//
// Created by User on 11/11/2025.
//

#ifndef NODO_HPP
#define NODO_HPP


#include "DetalleComanda.hpp"
#include "utils.hpp"

class Nodo {
private:
    class DetalleComanda dato;
    class Nodo *sig;

public:
    Nodo();
    virtual ~Nodo();
    friend class Cola;
};


#endif //NODO_HPP
