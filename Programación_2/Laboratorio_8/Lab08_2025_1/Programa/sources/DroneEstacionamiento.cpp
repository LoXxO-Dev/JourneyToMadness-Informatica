//
// Created by User on 7/11/2025.
//

#include "DroneEstacionamiento.hpp"

DroneEstacionamiento::DroneEstacionamiento() {
}

int DroneEstacionamiento::get_zona_carga() const {
    return zona_carga;
}


void DroneEstacionamiento::actualiza()  {
    //cout<<"open ";
    this->zona_carga=1;
}

bool DroneEstacionamiento::verificar() {
    return zona_carga==0;
}

void DroneEstacionamiento::imprimir(ofstream &arch) {
    Dron::imprimir(arch);
    arch<<right<<setw(20)<<zona_carga <<" Estacionamiento"<<endl;
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
