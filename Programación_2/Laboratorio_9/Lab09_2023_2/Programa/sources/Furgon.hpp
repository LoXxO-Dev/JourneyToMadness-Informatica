//
// Created by User on 24/11/2025.
//

#ifndef FURGON_HPP
#define FURGON_HPP


#include "NPedido.hpp"
#include "utils.hpp"
#include "Vehiculo.hpp"

class Furgon : public Vehiculo {
private:
    int filas;
    int puertas;
    list< class NPedido> pdeposito;

public:
    void lee(ifstream &arch);
     void imprime(ofstream &arch);
    void cargarDatos(ifstream &arch);
    int get_filas() const;

    void set_filas(int filas);

    int get_puertas() const;

    void set_puertas(int puertas);

    list<NPedido> get_pdeposito() const;

    void set_pdeposito(const list<NPedido> &pdeposito);
};


#endif //FURGON_HPP
