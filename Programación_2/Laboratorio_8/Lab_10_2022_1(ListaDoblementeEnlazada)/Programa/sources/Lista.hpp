//
// Created by User on 20/11/2025.
//

#ifndef LISTA_HPP
#define LISTA_HPP


#include "utils.hpp"

class Lista {
private:
    class Nodo *lini;
    class Nodo *lfin;

public:
    Lista();
    void leer(int codigo,ifstream &arch);
    void insertar(class Pedido * dato);
    void imprimir(ofstream &arch);
    void actualizar(int dni,int fecha);
};


#endif //LISTA_HPP
