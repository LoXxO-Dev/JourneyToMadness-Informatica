//
// Created by User on 20/11/2025.
//

#ifndef PEDIDOEVENTUAL_HPP
#define PEDIDOEVENTUAL_HPP


#include "Pedido.hpp"
#include "utils.hpp"
class PedidoEventual :public Pedido{
private:
    double flete;
public:
    double get_flete() const;

    void set_flete(double flete);
    void actualiza(int fecha);
    void lee(ifstream &arch);
    void imprimir(ofstream &arch);
};



#endif //PEDIDOEVENTUAL_HPP
