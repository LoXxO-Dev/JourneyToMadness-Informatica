//
// Created by User on 11/11/2025.
//

#ifndef LISTA_HPP
#define LISTA_HPP


#include "utils.hpp"

class Lista {
private:
    double peso = 0;
    class Nodo *ini;


public:
    Lista() {
        ini = nullptr;
    }
    double obtenerTotal();
    void actualiza();
    void imprimir(ofstream& arch);

    void insertar(class Libro *aux);
};


#endif //LISTA_HPP
