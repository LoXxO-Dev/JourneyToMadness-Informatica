//
// Created by User on 31/10/2025.
//

#include "PrioridadAlta.hpp"

void PrioridadAlta::imprime(ofstream &arch) {
    arch<<left<<setw(15)<<" ALTA";
    Pedido::imprime(arch);
    arch<<right<<setw(15)<<recargo<<endl;
}

void PrioridadAlta::actualiza() {
    this->total=recargo*Pedido::get_subtotal()/100;
    Pedido::set_total(Pedido::get_subtotal()+this->total);
}

double PrioridadAlta::get_recargo() const {
    return recargo;
}

void PrioridadAlta::set_recargo(double recargo) {
    this->recargo = recargo;
}

double PrioridadAlta::get_total() const {
    return total;
}

void PrioridadAlta::set_total(double total) {
    this->total = total;
}

void PrioridadAlta::leer(ifstream &arch) {
    Pedido::leer(arch);
    arch>>recargo;
}
