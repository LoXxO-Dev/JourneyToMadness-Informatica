//
// Created by User on 23/11/2025.
//

#include "Empresa.hpp"

Empresa::Empresa() {
}

Empresa::Empresa(const Empresa &orig) {
    dni=orig.get_dni();
    nombre=orig.get_nombre();
    distrito=orig.get_distrito();
}

Empresa::~Empresa() {

}

void Empresa::ingresarVehiculos(ifstream &arch) {
    class Vehiculo vehi;
    arch>>vehi;
    if (arch.eof()) return;
    vehiculos[vehi.get_placa()]=vehi;
}

bool Empresa::placaPresente(string placa) {
    for (auto &x: vehiculos) {
        if (x.first.compare(placa) == 0) return true;
    }
    return false;
}

void Empresa::ingresarMultasRecibidas(class Multa &mult) {

    multasRecibidas.push_back(mult);
    sort(multasRecibidas.begin(),multasRecibidas.end());

}

void Empresa::leer(ifstream &arch) {
    int documento;
    arch>>documento;
    if (arch.eof()) return;
    dni=documento;
    arch.get();
    getline(arch,nombre,',');
    getline(arch,distrito,'\n');
}

void Empresa::imprimir(ofstream &arch) {
    arch<<left<<setw(5)<<"DNI:"<<right<<setw(12)<<dni<<
        setw(15)<<" "<<left<<setw(10)<<"NOMBRE:"<<setw(45)<<nombre<<
            setw(10)<<"DISTRITO:"<<distrito<<endl;
    arch<<"VEHICULO DE LA EMPRESA"<<endl;
    arch<<left<<setw(15)<<"PLACA"<<setw(15)<<"MARCA"<<setw(15)<<"MODELO"<<endl;
    for (auto &x: vehiculos)
        x.second.imprimir(arch);
    imprimir_linea(arch,TAM_LINEA,'-');
    arch<<"MULTAS IMPUESTAS"<<endl;
    arch<<setw(15)<<left<<"PLACA"<<setw(25)<<"FECHA DE INFRACCION"
    <<setw(25)<<"CÓDIGO DE INFRACCIÓN"<<setw(15)<<"MULTA"<<setw(15)<<"PAGADA"
    <<setw(25)<<"FECHA DE PAGO"<<endl;
    for (auto &x: multasRecibidas)
        x.imprimir(arch);
}

void Empresa::elimminar() {
    vector<class Multa>::iterator it;
    it=multasRecibidas.begin();

    for (vector<class Multa>::iterator x=multasRecibidas.begin();x!=multasRecibidas.end();) {
        if (x->is_pagada()) {
            x=multasRecibidas.erase(x);
        }else
            ++x;
    }
}

int Empresa::get_dni() const {
    return dni;
}

bool Empresa::operator<(const class Empresa &empre) const {
    return dni<empre.dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

string Empresa::get_nombre() const {
    return nombre;
}

void Empresa::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

string Empresa::get_distrito() const {
    return distrito;
}

void Empresa::set_distrito(const string &distrito) {
    this->distrito = distrito;
}

void operator>>(ifstream &arch, Empresa &empre) {
    empre.leer(arch);
}
