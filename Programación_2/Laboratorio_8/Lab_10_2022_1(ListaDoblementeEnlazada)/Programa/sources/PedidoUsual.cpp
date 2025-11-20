//
// Created by User on 20/11/2025.
//

#include "PedidoUsual.hpp"

void PedidoUsual::lee(ifstream &arch) {
    arch>>descuento;
    arch.get();
    arch>>flete;
    arch.get();
    Pedido::lee(arch);

}

void PedidoUsual::imprimir(ofstream &arch) {
    Pedido::imprimir(arch);
    arch<<left<<setw(20)<<"Descuento:"<<descuento<<"%"<<endl;
    arch<<left<<setw(20)<<"Flete:"<<flete<<"%"<<endl<<endl;

}

void PedidoUsual::actualiza(int fecha) {
    if (Pedido::get_fecha()<fecha)
        flete=0;
}

double PedidoUsual::get_descuento() const {
    return descuento;
}

void PedidoUsual::set_descuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::get_flete() const {
    return flete;
}

void PedidoUsual::set_flete(double flete) {
    this->flete = flete;
}
