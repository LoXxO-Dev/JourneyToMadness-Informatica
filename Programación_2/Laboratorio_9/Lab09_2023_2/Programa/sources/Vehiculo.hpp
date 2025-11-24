//
// Created by User on 24/11/2025.
//

#ifndef VEHICULO_HPP
#define VEHICULO_HPP


#include "utils.hpp"
class Vehiculo {
private:
    int cliente;
    string placa;
    double maxcarga;
    double actcarga;

public:
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void cargarDatos(ifstream &arch)=0;
    int get_cliente() const;

    void set_cliente(int cliente);

    string get_placa() const;

    void set_placa(const string &placa);

    double get_maxcarga() const;

    void set_maxcarga(double maxcarga);

    double get_actcarga() const;

    void set_actcarga(double actcarga);
};



#endif //VEHICULO_HPP
