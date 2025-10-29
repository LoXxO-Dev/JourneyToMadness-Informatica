//
// Created by User on 7/10/2025.
//

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include "utils.hpp"

class Producto {
public:
    Producto();

    Producto(const Producto &copia);

    ~Producto();

    void operator =(const Producto &copia);

    void inicializa();

    bool operator +=(class Pedido &ped);

    double get_precio() const;

    void set_precio(double precio);


    int get_cantidad_clientes_servidos() const;

    void set_cantidad_clientes_servidos(int cantidad_clientes_servidos);

    int get_cantidad_clientes_no_servidos() const;

    void set_cantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);

    void get_codigo(char *codigo) const;

    void set_codigo(const char *codigo);

    void get_descripcion(char *descripcion) const;

    void set_descripcion(const char *descripcion);

    int get_stock() const;

    void set_stock(int stock);

    bool leer_producto(ifstream &arch);

    void imprimir(ofstream &arch);

    void imprimiLinea(ofstream &archivo, char car, int cantidad);

private:
    char *codigo;
    char *descripcion;
    int stock;
    double precio;
    int clientes_servidos[20];
    int clientes_no_servidos[20];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
};

bool operator>>(ifstream &arch, Producto &prod);

void operator<<(ofstream &arch, Producto &prod);

#endif //PRODUCTO_HPP
