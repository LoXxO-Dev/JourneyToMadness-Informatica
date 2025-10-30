//
// Created by User on 29/10/2025.
//

#ifndef PLATOFONDO_HPP
#define PLATOFONDO_HPP

#include "Producto.hpp"
#include "utils.hpp"

class PlatoFondo : public Producto {
private:
    int *proteina;

public:
    PlatoFondo();

    virtual ~PlatoFondo();

    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
};
void operator<<(ofstream &arch, PlatoFondo &p) ;

#endif //PLATOFONDO_HPP
