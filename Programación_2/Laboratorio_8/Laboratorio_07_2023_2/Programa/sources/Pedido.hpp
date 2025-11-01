//
// Created by User on 31/10/2025.
//

#ifndef PEDIDO_HPP
#define PEDIDO_HPP


#include "utils.hpp"

class Pedido {
private:
    char *codigo;
    int dni_cliente;
    double subtotal;
    int fecha;
    char *estado;
    double total;


public:
    Pedido();

    virtual ~Pedido();
     virtual void imprime(ofstream &arch);
    virtual void actualiza()=0;
    void get_codigo(char *codigo) const;

    virtual void leer(ifstream &arch);


    void set_codigo(const char *codigo);

    int get_dni_cliente() const;

    void set_dni_cliente(int dni_cliente);

    double get_subtotal() const;

    void set_subtotal(double subtotal);

    int get_fecha() const;

    void set_fecha(int fecha);

    void get_estado(char *estado) const;

    void set_estado(const char *estado);

    double get_total() const;

    void set_total(double total);
};


#endif //PEDIDO_HPP
