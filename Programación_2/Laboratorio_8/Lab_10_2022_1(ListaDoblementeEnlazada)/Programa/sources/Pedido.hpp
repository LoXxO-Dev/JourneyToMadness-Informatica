//
// Created by User on 20/11/2025.
//

#ifndef PEDIDO_HPP
#define PEDIDO_HPP


#include "utils.hpp"
class Pedido {
private:
    int codigo;
    string nombre;
    int cantidad;
    int dni;

public:
    virtual void lee(ifstream &arch);
    virtual void imprimir(ofstream &arch);
    virtual void actualiza(int fecha)=0;
    int get_codigo() const;

    void set_codigo(int codigo);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    int get_cantidad() const;

    void set_cantidad(int cantidad);

    int get_dni() const;

    void set_dni(int dni);

    int get_fecha() const;

    void set_fecha(int fecha);

    double get_total() const;

    void set_total(double total);

private:
    int fecha;
    double total;

};



#endif //PEDIDO_HPP
