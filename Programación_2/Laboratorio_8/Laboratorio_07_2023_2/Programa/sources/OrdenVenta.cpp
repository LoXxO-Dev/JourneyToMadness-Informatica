//
// Created by User on 31/10/2025.
//

#include "OrdenVenta.hpp"

#include "PrioridadAlta.hpp"
#include "PrioridadBaja.hpp"
#include "PrioridadMedia.hpp"

void OrdenVenta::lee(ifstream &arch) {
    //A,OTS-581,42157219,67.26,2023-11-07,7
    char tipo;
    arch >> tipo;
    if (arch.eof()) return;
    asignarTipo(tipo);
    arch.get();
    this->ptr_orden->leer(arch);
}

void OrdenVenta::imprime(ofstream &arch) {
    this->ptr_orden->imprime(arch);
}

void OrdenVenta::asignarTipo(char tipo) {
    switch (tipo) {
        case 'A':
            this->ptr_orden = new  class  PrioridadAlta;
            break;
        case 'B':
            this->ptr_orden = new class PrioridadBaja;
            break;
        case 'M':
            this->ptr_orden = new  class PrioridadMedia;
            break;
        default:
            break;
    }
}

void OrdenVenta::actualiza() {
    ptr_orden->actualiza();
}

void operator>>(ifstream &arch, OrdenVenta &orden) {
    orden.lee(arch);
}

void operator<<(ofstream &arch, OrdenVenta &orden) {
    orden.imprime(arch);
}
