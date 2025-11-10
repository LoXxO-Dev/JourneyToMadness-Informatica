//
// Created by User on 7/11/2025.
//

#include "DroneVelocidad.hpp"

bool DroneVelocidad::operator>(const class Dron &dron) const {
    return Dron::operator>(dron);

}


void DroneVelocidad::imprimir(ofstream &arch) {
    Dron::imprimir(arch);
    arch<<right<<setw(20)<<velocidad_maxima_permitida<<endl;

}


double DroneVelocidad::get_velocidad_maxima_permitida() const {
    return velocidad_maxima_permitida;
}

void DroneVelocidad::leer(ifstream &arch) {
    Dron::leer(arch);
    arch>>velocidad_maxima_permitida;
    arch.get();
}

void DroneVelocidad::actualiza() {

}

void DroneVelocidad::set_velocidad_maxima_permitida(double velocidad_maxima_permitida) {
    this->velocidad_maxima_permitida = velocidad_maxima_permitida;
}
