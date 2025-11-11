//
// Created by User on 11/11/2025.
//

#ifndef COLA_HPP
#define COLA_HPP

#include "utils.hpp"

class Cola {
private:
    int longitud=0;
    class Nodo *cabeza=nullptr;
    class Nodo *cola=nullptr;
    void Encolar(class DetalleComanda & aux);
    class Nodo * desencolar();

public:
    void elimina(int num);
    void imprimir(ofstream &arch);
    void leer(ifstream &archivo,int id);
};



#endif //COLA_HPP
