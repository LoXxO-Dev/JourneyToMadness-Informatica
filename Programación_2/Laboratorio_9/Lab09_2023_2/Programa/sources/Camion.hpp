//
// Created by User on 24/11/2025.
//

#ifndef CAMION_HPP
#define CAMION_HPP


#include "utils.hpp"
#include "Vehiculo.hpp"
#include "NPedido.hpp"
class Camion :public Vehiculo {
private:
    int ejes;
    int llantas;
    map<int,class NPedido> NPedido;

public:
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void cargarDatos(ifstream &arch);
    int get_ejes() const;

    void set_ejes(int ejes);

    int get_llantas() const;

    void set_llantas(int llantas);

};



#endif //CAMION_HPP
