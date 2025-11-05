//
// Created by User on 29/10/2025.
//

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP


#include "utils.hpp"

class Producto {
private:
    char *nombre;
    double precio;

public:
    Producto();

    virtual ~Producto();

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    double get_precio() const;

    void set_precio(double precio);

    void leer(ifstream &arch);

    void imprimir(ofstream &arch);

    void imprimir_linea(ofstream &arch, int cant, char car);
};


#endif //PRODUCTO_HPP
