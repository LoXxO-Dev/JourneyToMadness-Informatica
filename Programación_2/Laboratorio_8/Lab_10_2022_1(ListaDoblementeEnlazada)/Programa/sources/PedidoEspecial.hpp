//
// Created by User on 20/11/2025.
//

#ifndef PEDIDOESPECIAL_HPP
#define PEDIDOESPECIAL_HPP
#include "Pedido.hpp"


class PedidoEspecial :public Pedido{
private:
    double descuento;

public:
    void lee(ifstream &arch);
    void imprimir(ofstream &arch);
    void actualiza(int fecha);
    double get_descuento() const;

    void set_descuento(double descuento);
};



#endif //PEDIDOESPECIAL_HPP
