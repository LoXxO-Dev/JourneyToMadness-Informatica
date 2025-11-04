//
// Created by User on 4/11/2025.
//

#include "DroneEstacionamiento.hpp"

int DroneEstacionamiento::get_zona_carga() const {
    return zona_carga;
}

void DroneEstacionamiento::set_zona_carga(int zona_carga) {
    this->zona_carga = zona_carga;
}

void DroneEstacionamiento::leer(ifstream &arch) {
    Drone::leer(arch);
    char aux[100];
    arch.getline(aux,100, '\n');
    if (strcmp(aux,"true")==0) {
        zona_carga = 1;
    }else {
        zona_carga = 0;
    }

}

void DroneEstacionamiento::leerInfra(ifstream &arch,double &multa) {
    Drone::leerInfra(arch,zona_carga,multa);
}

void DroneEstacionamiento::imprimir(ofstream &arch) {
    Drone::imprimir(arch);
    arch<<right<<setw(10)<<zona_carga<<endl;
    Drone::imprimirInfra(arch);
    imprimirLinea(arch,TAM_LINEA-40,'*');

}
