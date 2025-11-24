//
// Created by User on 24/11/2025.
//

#ifndef NVEHICULO_HPP
#define NVEHICULO_HPP

#include "utils.hpp"
#include "Vehiculo.hpp"

class NVehiculo {
private:
    class Vehiculo *unidad;
public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    bool operator < (const class NVehiculo &aux)const ;
    bool encontrarPosicion(int dni);
    void ingresasPedido(ifstream &arch);
};



#endif //NVEHICULO_HPP
