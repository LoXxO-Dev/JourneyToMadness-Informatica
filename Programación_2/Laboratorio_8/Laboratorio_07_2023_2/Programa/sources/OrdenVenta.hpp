//
// Created by User on 31/10/2025.
//

#ifndef ORDENVENTA_HPP
#define ORDENVENTA_HPP

#include "utils.hpp"

class OrdenVenta {
private:
    class Pedido *ptr_orden;
public:
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void asignarTipo(char tipo);
    void actualiza();
};
void operator >>(ifstream &arch, OrdenVenta &orden) ;
void operator <<(ofstream &arch,OrdenVenta &orden);

#endif //ORDENVENTA_HPP
