//
// Created by User on 20/11/2025.
//

#ifndef NODO_HPP
#define NODO_HPP

#include "utils.hpp"

class Nodo {
private:
    class Pedido *ped;
    class Nodo *ant;
    class Nodo *sig;

public:
    Nodo();
    friend class Lista;
};


#endif //NODO_HPP
