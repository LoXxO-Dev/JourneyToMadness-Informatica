//
// Created by User on 4/11/2025.
//

#include "DroneSemaforo.hpp"

int DroneSemaforo::get_luz_roja() const {
    return luz_roja;
}

void DroneSemaforo::set_luz_roja(int luz_roja) {
    this->luz_roja = luz_roja;
}

void DroneSemaforo::leer(ifstream &arch) {
    Drone::leer(arch);
    char aux[100];
    arch.getline(aux,100, '\n');
    if (strcmp(aux,"true")==0) {
        luz_roja = 1;
    }else {
        luz_roja = 0;
    }
}

void DroneSemaforo::leerInfra(ifstream &arch,double &multa) {
    Drone::leerInfra(arch,luz_roja,multa);

}

void DroneSemaforo::imprimir(ofstream &arch) {
    Drone::imprimir(arch);
    arch<<right<<setw(10)<<luz_roja<<endl;
    Drone::imprimirInfra(arch);
    imprimirLinea(arch,TAM_LINEA-40,'*');

}
