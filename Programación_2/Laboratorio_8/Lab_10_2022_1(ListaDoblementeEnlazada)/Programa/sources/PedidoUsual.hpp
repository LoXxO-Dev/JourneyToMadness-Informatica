//
// Created by User on 20/11/2025.
//

#ifndef PEDIDOUSUAL_HPP
#define PEDIDOUSUAL_HPP

#include "Pedido.hpp"
#include "utils.hpp"

class PedidoUsual :public Pedido{
private:
    double descuento;
    double flete;

public:
    void lee(ifstream &arch);
    void imprimir(ofstream &arch);
    void actualiza(int fecha);
    double get_descuento() const;

    void set_descuento(double descuento);

    double get_flete() const;

    void set_flete(double flete);
};



#endif //PEDIDOUSUAL_HPP
