//
// Created by User on 18/11/2025.
//

#ifndef INFRACCION_HPP
#define INFRACCION_HPP

#include "utils.hpp"

class Infraccion {
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;

public:
    Infraccion();
    Infraccion(const Infraccion &orig);
    void operator =(const Infraccion &orig);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    bool operator <(const Infraccion &infraccion) const;


    string get_codigo() const;

    void set_codigo(const string &codigo);

    double get_multa() const;

    void set_multa(double multa);

    string get_gravedad() const;

    void set_gravedad(const string &gravedad);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);
};

void operator >>(ifstream &arch, Infraccion &infra);
void operator <<(ofstream &arch,Infraccion infra);



#endif //INFRACCION_HPP
