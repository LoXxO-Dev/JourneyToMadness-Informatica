//
// Created by User on 7/11/2025.
//

#ifndef NODO_HPP
#define NODO_HPP


class Nodo {
private:
    class Dron *dron;
    Nodo *izq;
    Nodo *der;
public:
    Nodo();
    friend class Arbol;
};


#endif //NODO_HPP
