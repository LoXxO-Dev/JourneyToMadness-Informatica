//
// Created by User on 18/11/2025.
//

#include "Vehiculo.hpp"

Vehiculo::Vehiculo() {
}

Vehiculo::Vehiculo(const Vehiculo &orig) {
    *this = orig;
}

void Vehiculo::operator=(const Vehiculo &orig) {
    placa=orig.placa;
    marca=orig.marca;
    modelo=orig.modelo;
}

void Vehiculo::leer(ifstream &arch) {
    string aux;
    getline(arch,aux,',');
    if (arch.eof()) return;
    placa=aux;
    getline(arch,marca,',');
    getline(arch,modelo,'\n');
}

void Vehiculo::imprimir(ofstream &arch) {
    arch<<left<<setw(15)<<placa<<
        setw(15)<<marca<<setw(15)<<
            modelo<<endl;
}

string Vehiculo::get_placa() const {
    return placa;
}

void Vehiculo::set_placa(const string &placa) {
    this->placa = placa;
}

string Vehiculo::get_marca() const {
    return marca;
}

void Vehiculo::set_marca(const string &marca) {
    this->marca = marca;
}

string Vehiculo::get_modelo() const {
    return modelo;
}

void Vehiculo::set_modelo(const string &modelo) {
    this->modelo = modelo;
}

void operator>>(ifstream &arch, Vehiculo &vehi) {
    vehi.leer(arch);
}

void operator<<(ofstream &arch, Vehiculo vehi) {
    vehi.imprimir(arch);
}

