//
// Created by User on 20/11/2025.
//

#include "PedidoEventual.hpp"

double PedidoEventual::get_flete() const {
    return flete;
}

void PedidoEventual::set_flete(double flete) {
    this->flete = flete;
}

void PedidoEventual::actualiza(int fecha) {
    if (Pedido::get_fecha()<fecha)
        flete=0;
}

void PedidoEventual::lee(ifstream &arch) {
    arch>>flete;
    arch.get();
    Pedido::lee(arch);

}

void PedidoEventual::imprimir(ofstream &arch) {
    Pedido::imprimir(arch);
    arch<<left<<setw(20)<<"Flete :"<<flete<<"%"<<endl<<endl;

}
