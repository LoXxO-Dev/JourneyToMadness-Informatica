//
// Created by User on 24/11/2025.
//

#ifndef NPEDIDO_HPP
#define NPEDIDO_HPP


#include "utils.hpp"
class NPedido {
private:
    string codigo;
    int cantidad;
    double peso;

public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    NPedido();
    NPedido(const NPedido &orig);
    void operator =(const NPedido &ped);
    string get_codigo() const;

    void set_codigo(const string &codigo);

    int get_cantidad() const;

    void set_cantidad(int cantidad);

    double get_peso() const;

    void set_peso(double peso);
};



#endif //NPEDIDO_HPP
