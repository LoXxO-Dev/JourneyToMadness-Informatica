//
// Created by User on 20/11/2025.
//

#include "PedidoEspecial.hpp"

void PedidoEspecial::lee(ifstream &arch) {
    arch>>descuento;
    arch.get();
    Pedido::lee(arch);

}

void PedidoEspecial::imprimir(ofstream &arch) {
    Pedido::imprimir(arch);
    arch<<left<<setw(20)<<"Descuento:"<<descuento<<"%"<<endl<<endl;
}

void PedidoEspecial::actualiza(int fecha) {

}

double PedidoEspecial::get_descuento() const {
    return descuento;
}

void PedidoEspecial::set_descuento(double descuento) {
    this->descuento = descuento;
}
