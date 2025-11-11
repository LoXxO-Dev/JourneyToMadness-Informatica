//
// Created by User on 7/11/2025.
//

#include "DroneSemaforo.hpp"

DroneSemaforo::DroneSemaforo() {

}

bool DroneSemaforo::verificar() {
    return luz_roja==1;
}



void DroneSemaforo::imprimir(ofstream &arch) {
    Dron::imprimir(arch);
    arch<<right<<setw(20)<<luz_roja<<endl;

}

void DroneSemaforo::actualiza()   {
   // cout<<"Entre";
    this->luz_roja=0;

}



int DroneSemaforo::get_luz_roja() const {
    return luz_roja;
}

void DroneSemaforo::leer(ifstream &arch) {
    Dron::leer(arch);
    char car[100];
    arch.getline(car, 100, '\n');
    if (strcmp(car,"true")==0)
        luz_roja = 1;
    else luz_roja = 0;
}

void DroneSemaforo::set_luz_roja(int luz_roja) {
    this->luz_roja = luz_roja;
}
