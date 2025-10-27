//
// Created by User on 5/10/2025.
//

#ifndef CLIENTE_HPP
#define CLIENTE_HPP


#include "utils.hpp"

class Cliente {
public:
    Cliente();

    Cliente(const Cliente &copia);

    ~Cliente();

    void operator =(const class Cliente &copia);

    bool posCliente(int dni);

    void agregarSubTotal(int cantidad, double descuentoPlato, double precioPlato);

    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    void get_distrito(char *distrito) const;

    void set_distrito(const char *distrito);

    double get_descuento() const;

    void set_descuento(double descuento);

    double get_total_pagado() const;

    void set_total_pagado(double total_pagado);

    void leerCliente(ifstream &arch);

    void imprimir(ofstream &arch);

private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;
};

void operator >>(ifstream &arch, class Cliente &cli);

void operator <<(ofstream &arch, class Cliente cli);

#endif //CLIENTE_HPP
