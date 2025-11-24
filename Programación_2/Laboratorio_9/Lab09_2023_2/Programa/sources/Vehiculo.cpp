//
// Created by User on 24/11/2025.
//

#include "Vehiculo.hpp"

void Vehiculo::lee(ifstream &arch) {
    arch>>cliente;
    arch.get();
    getline(arch,placa,',');
    arch>>maxcarga;
    arch.get();
    actcarga = maxcarga;

}

void Vehiculo::imprime(ofstream &arch) {
    arch<<left<<setw(15)<<"Codigo Cliente: "<<right<<setw(10)<<cliente<<endl;
    arch<<left<<setw(15)<<"Placa: "<<right<<setw(10)<<placa<<endl;
    arch<<left<<setw(15)<<"Carga Maxima: "<<right<<setw(10)<<maxcarga<<endl;
    arch<<left<<setw(15)<<"Carga Actual: "<<right<<setw(10)<<actcarga<<endl;
}



int Vehiculo::get_cliente() const {
    return cliente;
}

void Vehiculo::set_cliente(int cliente) {
    this->cliente = cliente;
}

double Vehiculo::get_maxcarga() const {
    return maxcarga;
}

void Vehiculo::set_maxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::get_actcarga() const {
    return actcarga;
}

void Vehiculo::set_actcarga(double actcarga) {
    this->actcarga = actcarga;
}
