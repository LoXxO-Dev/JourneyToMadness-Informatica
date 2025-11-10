//
// Created by User on 7/11/2025.
//

#include "DroneEstacionamiento.hpp"

int DroneEstacionamiento::get_zona_carga() const {
    return zona_carga;
}

bool DroneEstacionamiento::operator>(const class Dron &dron) const {
  return Dron::operator>(dron);
}

void DroneEstacionamiento::actualiza() {
    cout<<"Entre";
    this->zona_carga=10;
}

void DroneEstacionamiento::imprimir(ofstream &arch) {
    Dron::imprimir(arch);
    arch<<right<<setw(20)<<zona_carga<<"   ESTACIONAMIENTO" <<endl;
}


void DroneEstacionamiento::leer(ifstream &arch) {
    Dron::leer(arch);
    char car[100];
    arch.getline(car, 100, '\n');
    if (strcmp(car,"true")==0)
        zona_carga = 1;
    else zona_carga = 0;
}

void DroneEstacionamiento::set_zona_carga(int zona_carga) {
    this->zona_carga = zona_carga;
}
