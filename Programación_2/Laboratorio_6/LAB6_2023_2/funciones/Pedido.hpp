//
// Created by User on 7/10/2025.
//

#ifndef PEDIDO_HPP
#define PEDIDO_HPP


#include "utils.hpp"
class Pedido {
private:
    char *codigo;
    int dni_cliente;
    double precio_producto;

public:
    Pedido();
    ~Pedido();
    void  get_codigo(char *codigo) const;

    void set_codigo( const char *codigo);

    int get_dni_cliente() const;

    void set_dni_cliente(int dni_cliente);

    double get_precio_producto() const;

    void set_precio_producto(double precio_producto);
    bool leerPedido(ifstream &arch);
};
bool operator >>(ifstream &arch,class Pedido &ped);


#endif //PEDIDO_HPP
