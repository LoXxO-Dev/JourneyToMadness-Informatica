//
// Created by User on 18/11/2025.
//

#ifndef MULTA_HPP
#define MULTA_HPP


#include "utils.hpp"
class Multa {
private:
    int fecha;
    string placa;
    string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;

public:
    Multa();
    Multa(const Multa &orig);
    void operator =(const Multa &orig);
    bool operator <(const class Multa &mult)const ;
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);

    int get_fecha() const;

    void set_fecha(int fecha);

    string get_placa() const;

    void set_placa(const string &placa);

    string get_cod_multa() const;

    void set_cod_multa(const string &cod_multa);

    double get_multa() const;

    void set_multa(double multa);

    bool is_pagada() const;

    void set_pagada(bool pagada);

    int get_fecha_de_pago() const;

    void set_fecha_de_pago(int fecha_de_pago);
};
void operator >>(ifstream &arch, Multa &mult);
void operator <<(ofstream &arch,Multa multa);



#endif //MULTA_HPP
