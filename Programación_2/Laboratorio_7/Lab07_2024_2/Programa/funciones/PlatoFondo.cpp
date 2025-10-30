//
// Created by User on 29/10/2025.
//

#include "PlatoFondo.hpp"

PlatoFondo::PlatoFondo() {
    this->proteina = new int[4]{};
}

PlatoFondo::~PlatoFondo() {
    if (this->proteina != nullptr) delete this->proteina;
}

void PlatoFondo::leer(ifstream &arch) {
    Producto::leer(arch);
    bool primero = false;
    int categoria;
    for (int i = 0; i < 4; i++) {
        if (primero)arch.get();
        arch >> categoria;
        this->proteina[i] = categoria;


        primero = true;
    }
}

void PlatoFondo::imprimir(ofstream &arch) {
    Producto::imprimir(arch);
    arch << right<<setw(5);
    for (int i = 0; i < 4; i++)
        arch << setw(5)  << this->proteina[i];
    arch << endl;
}

void operator<<(ofstream &arch, PlatoFondo &p) {
    p.imprimir(arch);
}
