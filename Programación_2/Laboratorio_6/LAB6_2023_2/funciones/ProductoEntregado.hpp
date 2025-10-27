//
// Created by User on 7/10/2025.
//

#ifndef PRODUCTOENTREGADO_HPP
#define PRODUCTOENTREGADO_HPP

#include "utils.hpp"

class ProductoEntregado {
public:
    ProductoEntregado();

    void operator =(class Pedido &ped);

    void get_codigo(char *codigo) const;

    void set_codigo(const char *codigo);

    double get_precio() const;

    void set_precio(double precio);

private:
    char *codigo;
    double precio;
};


#endif //PRODUCTOENTREGADO_HPP
