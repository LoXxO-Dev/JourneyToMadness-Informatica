//
// Created by User on 28/10/2025.
//

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Utils.hpp"

class Cliente {
private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;
public:
    Cliente();
    virtual ~Cliente();
    Cliente(const class Cliente &orig);
    void operator=(const class Cliente &orig);
    void leer(ifstream &archivo);
    void imprimir(ofstream &archivo);
    int get_dni() const;

    void set_dni(int dni);

    void  get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

   void  get_distrito(char *distrito) const;

    void set_distrito(const char *distrito);

    double get_descuento() const;

    void set_descuento(double descuento);

    double get_total_pagado() const;

    void set_total_pagado(double total_pagado);


};

void operator >>(ifstream &arch,class Cliente &clie);
void operator <<(ofstream &arch,class Cliente &clie);
#endif //CLIENTE_HPP
