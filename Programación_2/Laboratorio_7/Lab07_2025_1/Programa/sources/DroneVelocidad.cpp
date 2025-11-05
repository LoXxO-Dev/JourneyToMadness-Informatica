//
// Created by User on 4/11/2025.
//

#include "DroneVelocidad.hpp"

int DroneVelocidad::get_velocidad_maxima_permitida() const {
    return velocidad_maxima_permitida;
}

void DroneVelocidad::set_velocidad_maxima_permitida(int velocidad_maxima_permitida) {
    this->velocidad_maxima_permitida = velocidad_maxima_permitida;
}

void DroneVelocidad::leer(ifstream &arch) {
    Drone::leer(arch);
    arch>>velocidad_maxima_permitida;
    arch.get();
}

void DroneVelocidad::leerInfra(ifstream &arch,double &multa) {
    Drone::leerInfra(arch,velocidad_maxima_permitida,multa);
}

void DroneVelocidad::imprimir(ofstream &arch) {
    Drone::imprimir(arch);
    arch<<right<<setw(10)<<velocidad_maxima_permitida<<endl;
    Drone::imprimirInfra(arch);
    imprimirLinea(arch,TAM_LINEA-40,'*');

}
