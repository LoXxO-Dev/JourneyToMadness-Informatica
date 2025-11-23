//
// Created by User on 18/11/2025.
//

#ifndef VEHICULO_HPP
#define VEHICULO_HPP


#include "utils.hpp"

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;

public:
    Vehiculo();
    Vehiculo(const Vehiculo &orig);
    void operator =(const Vehiculo &orig);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    string get_placa() const;

    void set_placa(const string &placa);

    string get_marca() const;

    void set_marca(const string &marca);

    string get_modelo() const;

    void set_modelo(const string &modelo);
};
void operator >>(ifstream &arch,Vehiculo &vehi);
void operator <<(ofstream &arch,Vehiculo vehi);


#endif //VEHICULO_HPP
